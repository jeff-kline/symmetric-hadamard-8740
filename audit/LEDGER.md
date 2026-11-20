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
