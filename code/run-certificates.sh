#!/bin/sh
# Build the order-8740 matrix from its formula, check it with two programs
# that share no code, and record its hash. Outputs go to the directory $1.
# Environment: CXX (C++17 compiler), CC (C compiler). About ten seconds on one core.
set -eu
out=${1:?output directory}
CXX=${CXX:-c++}
CC=${CC:-cc}
mkdir -p "$out/bin"
if command -v shasum >/dev/null 2>&1; then sha256() { shasum -a 256; }; else sha256() { sha256sum; }; fi
"$CXX" -std=c++17 -O2 -o "$out/bin/witness" code/witness.cpp
"$CC" -O2 -o "$out/bin/check8740" code/check8740.c

# 1. Build the matrix from the formula of Section 3 (packed: one bit per
#    entry, 1 = negative, most significant bit first, 1093 bytes per row).
"$out/bin/witness" build "$out/H8740.bin" > "$out/build.txt"

# 2. The builder's own check: symmetry and every row-pair distance.
"$out/bin/witness" check "$out/H8740.bin" > "$out/witness-check.txt"

# 3. Independent check (no shared code).
"$out/bin/check8740" "$out/H8740.bin" > "$out/check.txt"

# 4. Fingerprint of the packed matrix.
printf '%s  H8740.bin\n' "$(sha256 < "$out/H8740.bin" | cut -d' ' -f1)" > "$out/matrix-sha256.txt"
