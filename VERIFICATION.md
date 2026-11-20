# Verification record

## Environment of the pinned run (2026-11-19)

- macOS 26.6.2, x86_64, one core, run under `nice`.
- Apple clang 21.0.0, used as `c++ -std=c++17 -O2` and `cc -O2`.
- pdfTeX 3.141592653-2.6-1.40.22 (TeX Live 2021).

The programs need no network. Their SHA-256 hashes are in
[MANIFEST.sha256](MANIFEST.sha256).

## Commands

```sh
make verify CXX=c++ CC=cc
make paper
```

`make verify` runs [code/run-certificates.sh](code/run-certificates.sh). It
builds the matrix into `build/certificates/H8740.bin`, writes four outputs and
compares each byte for byte with its pinned copy in [evidence/](evidence/). It
takes about ten seconds.

## What each certificate checks

| Step | Program | Pinned output |
|---|---|---|
| Build the matrix of Section 3 from its formula over $\mathbb F_{19}$ and $\mathbb F_{23}$. The build prints nothing on success. | `witness.cpp build` | `build.txt` |
| The builder's own check: symmetry on all 38189430 transposed pairs, and Hamming distance 4370 between every pair of distinct rows. | `witness.cpp check` | `witness-check.txt` |
| An independent check, sharing no code with the builder. It checks file size, zero padding, symmetry and every row-pair distance. A copy with one flipped entry fails. | `check8740.c` | `check.txt` |
| SHA-256 of the packed matrix: 8740 rows of 1093 bytes, one bit per entry, 1 for a negative entry, most significant bit first. | `run-certificates.sh` | `matrix-sha256.txt` |

A separate AI review pass also reconstructed the matrix from the formula in
separate code and found it byte-identical (see [audit/LEDGER.md](audit/LEDGER.md)).

## Paper build

`make paper` runs pdfLaTeX three times with a fixed `SOURCE_DATE_EPOCH` and
fails on any warning, overfull box or undefined reference.
