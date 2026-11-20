// Reconstruct order 8740 from its finite-field formula, or check a raw witness.
#include <array>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

constexpr int q = 19, t = 23, outer = (q + 1) * q, n = outer * t;
constexpr int bytes = (n + 7) / 8, words = (n + 63) / 64;

template<int p> std::array<int, p> character() {
    std::array<int, p> table;
    table.fill(-1);
    table[0] = 0;
    for (int x = 1; x < p; ++x) table[x * x % p] = 1;
    return table;
}

void build(const char* path) {
    const auto chi = character<q>();
    const auto eta = character<t>();
    std::array<std::array<int,t>,t> core{}, plug{};
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < t; ++j) {
            int k = (t-j) % t;
            core[i][j] = -((i == k) + eta[(t+k-i) % t]);
            plug[i][j] = 1 - 2 * (i == j);
        }
    }
    std::ofstream out(path, std::ios::binary);
    for (int a = 0; a <= q; ++a) {
        for (int x = 0; x < q; ++x) {
            std::array<int,outer> u{}, v{};
            for (int b = 0; b <= q; ++b) {
                // Index 0 is infinity. Finite field element z has index 1+z.
                int k = b == 0 ? 0 : 1 + (q+1-b) % q;
                int sign = b == 0 ? -1 : 1;
                int c = (a == k) ? 0 : a == 0 ? 1 : k == 0 ? -1 : chi[(q+k-a) % q];
                for (int y = 0; y < q; ++y) {
                    int z = (q-y) % q;
                    u[b*q+y] = sign * ((a == k) + c * chi[(q+z-x) % q]);
                    v[b*q+y] = sign * c * (x == z);
                }
            }
            for (int i = 0; i < t; ++i) {
                std::array<unsigned char,bytes> row{};
                for (int block = 0; block < outer; ++block) {
                    for (int j = 0; j < t; ++j) {
                        int entry = u[block]*core[i][j] + v[block]*plug[i][j];
                        if (entry != 1 && entry != -1) throw std::runtime_error("non-sign entry");
                        int col = block*t+j;
                        if (entry < 0) row[col/8] |= 0x80 >> (col%8);
                    }
                }
                out.write(reinterpret_cast<const char*>(row.data()), bytes);
            }
        }
    }
    out.close();
    if (!out) throw std::runtime_error("write failed");
}

void check(const char* path) {
    std::ifstream in(path, std::ios::binary);
    using Row = std::array<std::uint64_t, words>;
    std::vector<Row> rows(n, Row{});
    for (auto& row : rows) {
        std::array<unsigned char,bytes> packed{};
        if (!in.read(reinterpret_cast<char*>(packed.data()), bytes))
            throw std::runtime_error("missing data");
        if (packed.back() & 15) throw std::runtime_error("nonzero padding");
        for (int j = 0; j < n; ++j) {
            if (packed[j/8] & (0x80 >> (j%8))) row[j/64] |= std::uint64_t(1) << (j%64);
        }
    }
    if (in.peek() != std::char_traits<char>::eof()) throw std::runtime_error("excess data");
    std::uint64_t pairs = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (((rows[i][j/64] >> (j%64)) ^ (rows[j][i/64] >> (i%64))) & 1)
                throw std::runtime_error("asymmetric entry");
            int distance = 0;
            for (int k = 0; k < words; ++k)
                distance += __builtin_popcountll(rows[i][k] ^ rows[j][k]);
            if (2*distance != n) throw std::runtime_error("nonorthogonal rows");
            ++pairs;
        }
    }
    std::cout << "Order " << n << ". Symmetry verified on " << pairs
              << " pairs. Every distinct row pair has distance " << n/2 << ".\n";
}

int main(int argc, char** argv) {
    try {
        if (argc != 3) throw std::runtime_error("usage: witness build|check FILE");
        std::string mode = argv[1];
        if (mode == "build") build(argv[2]);
        else if (mode == "check") check(argv[2]);
        else throw std::runtime_error("unknown mode");
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}
