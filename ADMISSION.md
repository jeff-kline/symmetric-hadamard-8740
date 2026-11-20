# Admission record

**Current state:** CANDIDATE

Current verdict: NOT YET ADMITTED

**Version:** 0.1.0 (release candidate)

**Standard:** [A Public Standard for This Work](https://jeff-kline.github.io/posts/research-program/index.html)

Admission is a project release decision. It is not peer review, a correctness
certificate, or proof of global novelty.

**Scope set by the author.** On 2026-11-19 the author asked for this note to
be its own release, after the fixes from review. The author approved the
abstract and README introduction on 2026-11-20.

## Principal claim

There is a symmetric Hadamard matrix of order $8740=4\cdot2185$, an entry
listed as undecided in the 2025 Đoković–Seberry census. More generally,
symmetric Hadamard matrices of orders $(q+1)(q+4)q^r$ exist for every prime
power $q\equiv3\pmod4$ with a symmetric Hadamard matrix of order $q+5$, and all
$r\ge0$. The case $r=0$ is Kumar's; the lift for $r\ge1$ is new in the sources
examined.

## Gates

| Gate | Status | Evidence or residual |
|---|---|---|
| P1 prior work and credit | PARTIAL | `audit/PRIOR-ART.md` and the search log. Residuals: the Handbook chapter, Seberry–Yamada and Seberry (1981) were not read |
| A1 claim and artifact consistency | PASS | Cold examiner (Stage 1 NOT-BROKEN, Stage 2 VERIFIED, 7 errata applied) and one combined release audit (10 findings); dispositions in `audit/LEDGER.md` |
| R1 release and stewardship | IN PROGRESS | `make verify` (4 MATCH) and a deterministic `make paper` pass, also from a clean `git archive`; correction policy, CITATION.cff and MANIFEST.sha256 present. No tag, archive or DOI yet |
