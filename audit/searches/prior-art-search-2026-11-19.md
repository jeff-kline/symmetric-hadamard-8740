# Prior-art search, 2026-11-19

Each search is logged with its date and query. A failed or inaccessible
search is recorded as NOT PERFORMED, not as a negative result.

## Sources read

- **Seberry (1980),** *Some infinite classes of Hadamard matrices*, J. Austral. Math. Soc. A 29, 235–242 (Cambridge PDF).
  - Corollary 2(b) gives Hadamard matrices of order $p^j(p+1)(p+4)$ from a symmetric Hadamard matrix of order $p+5$, stated for ordinary matrices.
  - The closing remark on p. 241 only suggests that Whiteman's methods might give symmetric matrices.
- **Spence (1977),** *An infinite family of Williamson matrices*, J. Austral. Math. Soc. A 24, 252–256 (Cambridge PDF).
  - Symmetric results (Corollaries 2–3) only for $q\equiv1\pmod4$, of order $2q^r(q+1)$.
  - For $q\equiv3\pmod4$ the outputs are ordinary (Theorem 6, Corollary 7, Theorem 10).
- **Đoković–Seberry census,** PDF dated 2025-05-28 (SHA-256 `4b61953c…f04a`):
  - $v=2185$ is in the symmetric undecided list (p. 5);
  - so are 1207 and 189.
- **`vatskishan03/Hadamard` at d885022 (HEAD on 2026-11-19):** `symmetric/README.md`, `symmetric/4828/README.md`, `search/NOTES.md`, `NOVELTY.md`.
  - 460 and 4828 (the case $r=0$) are recorded as a symmetric form of the Williamson–Wallis $m(m+3)$ construction, "New, but obtainable classically".
  - Order 8740 is not recorded.
  - `search/NOTES.md` seeks $4\cdot2185$ only through a symmetric OD(92; 1, 91), described as unknown.
  - The 4828 README states that no classical source gives the symmetric version.
- **arXiv, read in full and searched for 8740, 2185 and the family:**
  - 2508.17141, 2101.05429, 2301.02751, 1803.08787 (Đoković);
  - 1512.01732 (Balonin–Seberry, propus);
  - 1708.05098, 1710.03037, 1503.04226;
  - 2610.27175 (2026 survey), 2411.18897, 2306.16812, 2608.06920.

  No hits.
- **SageMath** `hadamard_matrix.py` (develop, 2026-11-19): no symmetric constructor covers 8740 or the family.

## Searches

| Date | Query | Result |
|---|---|---|
| 2026-11-19 | OpenAlex: works citing Seberry 1980 (8) and Spence 1977 (11) | titles screened; none on symmetric Hadamard matrices or symmetric orthogonal designs |
| 2026-11-19 | OpenAlex topical searches (symmetric Hadamard recursive constructions, symmetric orthogonal designs, symmetric Williamson-type) | nothing on the family |
| 2026-11-19 | arXiv API: `all:"symmetric Hadamard"`, `all:"symmetric orthogonal design"`, `all:propus` | the relevant entries are read above; the exact-phrase query returned 0 |
| 2026-11-19 | GitHub positive control `gh search code skew hadamard 1528` | hit `vatskishan03/Hadamard` |
| 2026-11-19 | `gh search code 8740 symmetric hadamard`, `gh search code 2185 symmetric` | unrelated hits only |
| 2026-11-19 | `gh search code 8740 --repo vatskishan03/Hadamard` | numerical noise only |

## Not performed

- The Handbook of Combinatorial Designs, Craigen–Kharaghani chapter: not accessible.
- Seberry–Yamada (1992, 2020): not accessible.
- The journal text of Seberry–Balonin (2017); only its arXiv preprint was read.
- Wallis (1969, 1970, 1975): known only through quotations in the public index.
- Seberry (1981), *Recurrence formulas for the construction of Williamson-type matrices*, which cites Spence 1977: not read.
- Google Scholar, MathSciNet, zbMATH: not accessible.
