# Audit ledger

This file is append-only. The auditors are AI agents in fresh contexts; they
are not independent expert reviewers. Finding labels: error, gap, missing
hypothesis, sharpening, documentation.

## 2026-11-19 — review of the working note

- **Proof check by the release agent.** Every identity in the proof of
  Theorem 1, the corollary and the order-24 seed was checked by hand.
- **Independent checker.** `check8740.c` was written for this review and
  shares no code with `witness.cpp`. It passes all 38189430 row pairs, and a
  copy with one flipped bit fails.
- **Fixes from that check:**
  - an off-topic aside on order 2116 and a related-work paragraph listing
    unrelated papers were removed;
  - the T1 font encoding, which produced Type 3 bitmap fonts and a broken text
    layer, was removed;
  - a section sign that pulled in a bitmap font became "Section 2".
- **Cold examiner, Stage 1** (statements only, sealed SHA-256 ac088047…a6ab):
  NOT-BROKEN for all claims.
  - It re-derived the lift, the corollary and the seed for general $q$.
  - It checked small cases at orders 28, 84, 252, 88, 616, 180, 1980 and 460.
  - It checked the full Gram matrix of the 8740 file exactly.
- **Cold examiner, Stage 2** (proof audit, sealed SHA-256 ca257dfa…6a75):
  VERIFIED, no gap.
  - An independent reconstruction from the formula is byte-identical to the
    witness file.
  - The proof uses nothing specific to prime fields; it was checked exactly at
    $q=27$.
  - Seven errata, all applied:
    1. (error, attribution) The case $r=0$ is Kumar's symmetric form of the
       Williamson–Wallis $m(m+3)$ construction, not "classical". The text and
       abstract now credit Kumar.
    2. (sharpening) The family's undecided census members are exactly 2185,
       1207 and 189.
    3. (documentation) The verification paragraph now states that the file is
       the formula's matrix, with its conventions.
    4. (documentation) Order of inferences, and $XY=YX$ named where used.
    5. (documentation) "Sign matrix" is defined at first use.
    6. (documentation) The checker's usage line and argument check.
    7. (documentation) The census citation.
- **Prior art.** A read-only pass found no earlier record; the residuals are
  in `audit/PRIOR-ART.md`.

## 2026-11-19 — combined release audit of draft commit 3ec7a80

A read-only audit (Sonnet) covered claims, citations and reproducibility.

**Verdict:** PASS-WITH-FIXES. The audit confirmed:
- `make verify` gives 4 MATCH from a clean archive;
- `make paper` is identical from two clean extractions, with all fonts Type 1;
- the arithmetic, the cross-references and the text of the proof;
- the Crossref metadata for the four DOIs.

Findings and dispositions:

1. (error, attribution) Kumar's index records 4828, not 460. The order 460
   is checked in his construction notes. Fixed in the paper, README,
   PRIOR-ART and the search log.
2. (gap) Wallis was cited by exact theorem and corollary without the papers
   being read.
   - The Bull. Austral. Math. Soc. 1975 paper was then read: in the proof of
     Theorem 1, $(cI+dQ)R$ is a symmetric type 2 matrix, confirming the
     field-negation citation.
   - The Linear Multilinear Algebra 1975 Corollary 4 is a scan without a text
     layer, so the paper now cites it "as quoted in Kumar's notes".
3. (gap) "Exactly three census entries" had no record in the repository.
   Added `audit/census-family.md`: all 15 members with $v<2500$, checked
   against the 595 undecided values parsed from the census text. 189, 1207
   and 2185 are undecided; 517 and the rest are decided.
4. (documentation) The MANIFEST.sha256 link was dead. Added at the candidate.
5. (documentation) Dates. The pinned run is dated 2026-11-19; the paper's
   date is the release date.
6. (sharpening) Process wording in README and VERIFICATION was replaced with
   "AI review passes, not human peer review", with a link to this ledger.
7. (sharpening) "the two census lists" became "the census or Kumar's index".
8. (documentation) `$v<2500$` rendering: unchanged. GitHub renders it as
   math, and the same form is used in the earlier releases.
9. (documentation) CITATION.cff lists two references; the DOI and release date
   are added after archiving.
10. (documentation) The unused `\zen` macro was removed.

## 2026-11-20 — tag, archive and admission

- Pre-tag rescan: nothing new (see the search log).
- Tag `v0.1.0` (object `1346f2e`) → `24bae54`; the tagged-state audit passed
  8 of 8. The GitHub Release was published at 2026-11-20 00:16 UTC.
- Zenodo record 24383049 (version DOI 10.5281/zenodo.24383049, concept DOI 10.5281/zenodo.24383048). The Zenodo
  file is byte-identical to the GitHub zipball pinned before the Release
  (SHA-256 `363962b6…`); the archived-state audit passed 12 of 12.
- Living metadata: README status paragraph and DOI badge, `CITATION.cff` DOI,
  identifiers and `date-released`, the note's DOI line, ADMISSION ADMITTED,
  the CORRECTIONS version history and the rescan record.
