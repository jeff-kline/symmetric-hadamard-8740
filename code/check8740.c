/* Independent check of the packed order-8740 matrix (shares no code with
   witness.cpp). Format: 8740 rows; each row is 1093 bytes, one bit per entry,
   1 = negative sign, most significant bit first, the last 4 bits zero.
   Checks file size, zero padding, symmetry, and that every pair of distinct
   rows has Hamming distance 4370 (inner product 0).
   cc -O2 -o check8740 check8740.c && gzip -dc 8740.bin.gz > m.bin && ./check8740 m.bin */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8740
#define RB 1093                 /* bytes per row */
#define W ((RB + 7) / 8)        /* 64-bit words per row */
static unsigned char raw[N][RB];
static uint64_t R[N][W];

static int bit(int i, int j) { return (raw[i][j >> 3] >> (7 - (j & 7))) & 1; }

int main(int argc, char **argv) {
  if (argc != 2) { fprintf(stderr, "usage: %s FILE\n", argv[0]); return 2; }
  FILE *f = fopen(argv[1], "rb");
  if (!f) { perror("open"); return 2; }
  if (fread(raw, 1, sizeof raw, f) != sizeof raw) { puts("short file"); return 2; }
  if (fgetc(f) != EOF) { puts("file too long"); return 2; }
  fclose(f);
  for (int i = 0; i < N; i++) {
    if (raw[i][RB - 1] & 0x0F) { printf("nonzero padding in row %d\n", i); return 1; }
    memcpy(R[i], raw[i], RB);   /* XOR distance is independent of byte order */
  }
  long pairs = 0;
  for (int i = 0; i < N; i++)
    for (int j = i + 1; j < N; j++) {
      if (bit(i, j) != bit(j, i)) { printf("not symmetric at %d,%d\n", i, j); return 1; }
      pairs++;
    }
  for (int i = 0; i < N; i++)
    for (int k = i + 1; k < N; k++) {
      int d = 0;
      for (int w = 0; w < W; w++) d += __builtin_popcountll(R[i][w] ^ R[k][w]);
      if (d != N / 2) { printf("rows %d,%d have distance %d\n", i, k, d); return 1; }
    }
  printf("PASS: order %d, symmetric on %ld pairs, all %ld distinct row pairs at distance %d\n",
         N, pairs, pairs, N / 2);
  return 0;
}
