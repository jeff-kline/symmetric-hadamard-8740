# A symmetric Hadamard matrix of order 8740

Jeffery Kline

[![Version DOI: 10.5281/zenodo.24383049](https://zenodo.org/badge/DOI/10.5281/zenodo.24383049.svg)](https://doi.org/10.5281/zenodo.24383049)

**Status: version 0.1.0 admitted 2026-11-20.** The immutable release is
[`v0.1.0`](https://github.com/jeff-kline/symmetric-hadamard-8740/releases/tag/v0.1.0), archived at version DOI
[`10.5281/zenodo.24383049`](https://doi.org/10.5281/zenodo.24383049). The concept DOI
[`10.5281/zenodo.24383048`](https://doi.org/10.5281/zenodo.24383048) resolves to the latest version; cite the
version DOI for reproducibility. Admission under the project's
[public research standard](https://jeff-kline.github.io/posts/research-program/index.html)
is a release decision, not peer review or a correctness certificate; see
[ADMISSION.md](ADMISSION.md). The tagged snapshot retains its prepublication
“release candidate” wording because the DOI did not exist when it was made.

The note is [paper/main.pdf](paper/main.pdf); its source is
[paper/main.tex](paper/main.tex).

## Introduction

The 2025 census of Đoković and Seberry lists $v=2185$ among the odd $v<2500$
for which the existence of a symmetric Hadamard matrix of order $4v$ is
undecided. This note constructs a symmetric Hadamard matrix of order
$8740=4\cdot2185$.

The matrix is the first step of an infinite family. For every prime power
$q\equiv3\pmod4$ for which a symmetric Hadamard matrix of order $q+5$ exists,
there are symmetric Hadamard matrices of orders $(q+1)(q+4)q^r$ for all
$r\ge0$. Seberry (1980) obtained these orders for ordinary Hadamard matrices,
and Kumar gave the symmetric case $r=0$. The note builds field negation
$x\mapsto-x$ into each step of Seberry's recursion, so that the two component
matrices stay symmetric and commute at every level. At $q=19$, with a symmetric
matrix of order 24, this gives symmetric Hadamard matrices of orders
$460\cdot19^r$ for all $r$; the case $r=1$ is the order 8740.

## What is new

Seberry's 1980 recursion gives the orders $(q+1)(q+4)q^r$ for ordinary
Hadamard matrices. Kumar's public index gives the symmetric case $r=0$, as a
symmetric form of the Williamson–Wallis $m(m+3)$ construction on Paley's
symmetric orthogonal design; the index records the order 4828, and its
construction notes check the case $q=19$ (order 460). New here:

1. **Principal result: a symmetric Hadamard matrix of order 8740**, settling
   the census entry $v=2185$ (paper Section 3).
2. **The symmetric recursion** (Theorem 1). Let $q\equiv3\pmod4$ be a prime
   power, and let $X,Y$ be commuting symmetric $\pm1$ matrices of order $t$
   with $X^2+qY^2=(q+1)tI$. Then symmetric Hadamard matrices of order
   $(q+1)tq^r$ exist for every $r\ge0$. The lift to each $r\ge1$ is the new
   step.
3. **The family** (Corollary 2). For every prime power $q\equiv3\pmod4$ with
   a symmetric Hadamard matrix of order $q+5$, symmetric Hadamard matrices of
   orders $(q+1)(q+4)q^r$ exist for all $r\ge0$. Of the census's undecided
   entries, the family contains exactly 2185, 1207 ($r=0$, already in Kumar's
   index) and 189 (settled by Đoković in 2025 by another construction).

These statements rest on a bounded comparison recorded in
[audit/PRIOR-ART.md](audit/PRIOR-ART.md). We found no earlier symmetric
construction at order 8740, or of the recursion for $r\ge1$, in the sources
examined. This is not a claim of global priority.

## Earlier work

- **Seberry (1980)**,
  [*Some infinite classes of Hadamard matrices*](https://doi.org/10.1017/S1446788700021212),
  Corollary 2(b): the orders $(q+1)(q+4)q^r$ for ordinary Hadamard matrices.
- **Spence (1977)**,
  [*An infinite family of Williamson matrices*](https://doi.org/10.1017/S1446788700020255):
  the recursive orthogonal design.
- **Kumar (2026)**, public index
  [`vatskishan03/Hadamard`](https://github.com/vatskishan03/Hadamard): the symmetric case $r=0$
  (order 4828 in the index; order 460 checked in its construction notes).
- **Đoković and Seberry (2025)**, census of symmetric and skew Hadamard
  matrices of order $4v$, $v$ odd below 2500: lists 2185 as undecided.

## Evidence and limits

| Claim | Status |
|---|---|
| Theorem 1 (symmetric recursion) and Corollary 2 | proved on paper; checked in two separate AI review passes, not human peer review (see [audit/LEDGER.md](audit/LEDGER.md)) |
| The matrix of order 8740 | certified computation: built from its formula and checked by two programs that share no code |
| Priority at 8740 and for the lift | bounded search; see [audit/PRIOR-ART.md](audit/PRIOR-ART.md) |

Limits: the family needs a symmetric Hadamard matrix of order $q+5$. Among
the census entries below 2500 it reaches exactly three undecided ones: 2185,
1207 and 189 (see [audit/census-family.md](audit/census-family.md)).

## Reproduce

The certificates need a C++17 compiler and a C compiler; the note needs
pdfLaTeX.

```sh
make verify   # about ten seconds on one core
make paper
```

`make verify` builds the matrix from its formula, checks it with two programs
that share no code, and compares each output with its pinned copy in
`evidence/`.

## Role of AI

AI assisted the derivations, the computer verification, the literature search
and the exposition under the author's direction. Process-separated AI reviews
checked the proofs and certificates; they are not independent expert peer
review, and no independent human expert has examined the proofs. The audits
and their dispositions are in [audit/LEDGER.md](audit/LEDGER.md).

## License

GPL-3.0-only. See [LICENSE](LICENSE).
