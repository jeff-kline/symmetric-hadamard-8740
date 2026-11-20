# Prior art and credit

This is a bounded comparison. It is not a claim of global novelty. The searches
are logged in
[searches/prior-art-search-2026-11-19.md](searches/prior-art-search-2026-11-19.md).

**Claim:** we found no earlier symmetric Hadamard matrix of order
$8740=4\cdot2185$, and no earlier symmetric form of Seberry's recursion for
$r\ge1$, in the sources examined.

| Source | What it records | Bearing |
|---|---|---|
| Seberry (1980), Theorem 1 and Corollary 2(b) | the general ordinary recursion on amicable pairs (Theorem 1); the orders $(q+1)(q+4)q^r$ from a symmetric matrix of order $q+5$ (Corollary 2(b)) | the recursion, the orders and the seed; credited |
| Spence (1977) | the recursive orthogonal design; symmetric outputs only for $q\equiv1\pmod4$ | credited |
| Wallis, Bull. Austral. Math. Soc. 12 (1975), proof of Theorem 1 (read, Cambridge PDF) | $(cI+dQ)R$ with $R$ the reversal $x\mapsto-x$ is a symmetric type 2 matrix: field negation in a symmetric orthogonal design | credited |
| Wallis, Linear Multilinear Algebra 3 (1975), Corollary 4 | lists 2185 as a Williamson-type component order | cited as quoted in Kumar's notes (the scan has no text layer; not read) |
| Kumar, `vatskishan03/Hadamard` (d885022) | symmetric case $r=0$: order 4828 in the index; the general case and the check at $q=19$ (order 460) in `search/NOTES.md`; seeks 8740 by another route | credited for $r=0$ and the completion step |
| Đoković–Seberry census (2025) | 2185, 1207 and 189 undecided | the entry settled here |
| Đoković (2025), arXiv:2508.17141 | settles 189 by another construction | consistent |
| Survey and database papers (arXiv 2610.27175, 2411.18897), SageMath | no 8740 and no symmetric family | consistent |

## Residuals

- The Craigen–Kharaghani Handbook chapter and Seberry–Yamada were not
  accessible.
- Seberry (1981), *Recurrence formulas for the construction of Williamson-type
  matrices*, which cites Spence 1977, was not read. It is the most plausible
  place for an undetected symmetric variant.
- Wallis (1969, 1970) and Wallis, Linear Multilinear Algebra (1975), are known
  only through quotations in Kumar's notes.
- Forward citations are from OpenAlex only; coverage is incomplete.
- Unpublished or unindexed constructions cannot be excluded.
