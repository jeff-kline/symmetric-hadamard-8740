# Admission record

**Current state:** ADMITTED

Current verdict: ADMITTED (2026-11-20)

**Version:** 0.1.0

**Tag:** `v0.1.0` → `24bae549e792579497f0a3f78852a84f2996082e`

**Version DOI:** [`10.5281/zenodo.24383049`](https://doi.org/10.5281/zenodo.24383049) · **Concept DOI:** `10.5281/zenodo.24383048` · **Record:** <https://zenodo.org/records/24383049>

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
| P1 prior work and credit | PARTIAL, residual accepted | `audit/PRIOR-ART.md` and the search log. Residuals: the Handbook chapter, Seberry–Yamada and Seberry (1981) were not read. A rescan on 2026-11-20 at 00:15 UTC, before the tag, found nothing new. The author approved the freeze with these residuals stated |
| A1 claim and artifact consistency | PASS | Cold examiner (Stage 1 NOT-BROKEN, Stage 2 VERIFIED, 7 errata applied) and one combined release audit (10 findings); dispositions in `audit/LEDGER.md` |
| R1 release and stewardship | PASS | See below |

## R1 — release and stewardship

| Check | Status | Evidence or residual |
|---|---|---|
| Reproduction | PASS | fresh `git archive` extraction of the draft and of the candidate: `make verify` 4 MATCH; deterministic `make paper`, byte-identical to the committed PDF |
| Artifact integrity | PASS | `MANIFEST.sha256` covers every tracked file |
| Hygiene | PASS | README, verification, prior-art and census-family math rendered by GitHub, every span recognized |
| Stewardship | PASS | `CORRECTIONS.md` |
| Immutable semantic tag | PASS | annotated `v0.1.0` (object `1346f2e`) → `24bae54`; tagger is the GitHub noreply identity |
| Public permanent archive with provider byte identity | PASS | the pinned GitHub `zipball/v0.1.0` (downloaded twice, identical) and the Zenodo file are byte-identical: 236435 bytes, SHA-256 `363962b64094a7e46a1aa13307f91eb1b3ee770dfd1515482bcdd4007474b45c`; Zenodo MD5 `3e427704cc7c9c61894fd24644676607` |
| DOI resolves; living repository identifies the version | PASS | `doi.org/10.5281/zenodo.24383049` redirects to the Zenodo record; README, `CITATION.cff` and the living paper carry the version DOI |
| Archive metadata matches repository | PASS | title, creator Kline, Jeffery, version v0.1.0, publication date 2026-11-20, license `gpl-3.0`, resource type software |
| Machine-readable citation | PASS | `CITATION.cff` with version DOI, concept DOI and `date-released: 2026-11-20` |

**Admission verdict:** ADMITTED (2026-11-20). The P1 residuals and the limits
stated in the README remain. No independent human expert has reviewed the
note.

## Archive verification

- Route: Zenodo GitHub integration; no manual deposit.
- Pinned before the GitHub Release: GitHub API `zipball/v0.1.0`, downloaded
  twice, identical, 236435 bytes, SHA-256
  `363962b64094a7e46a1aa13307f91eb1b3ee770dfd1515482bcdd4007474b45c`.
- Zenodo file `jeff-kline/symmetric-hadamard-8740-v0.1.0.zip`: identical to
  the pinned zipball.
- Separate determinism check: `git archive --format=zip v0.1.0`, generated
  twice, identical, 233933 bytes, SHA-256
  `68285432eb01b8808698db838222562a4b8f7033ed94f642b770206ba952c559`; a
  different file from the provider zipball, not compared with it.
- Mechanical audit at the archived state, on the unchanged tagged tree:
  12 pass, 0 warnings, 0 fail.

## External actions and owners

| Action | Owner | Status |
|---|---|---|
| Private GitHub repository and push | author authorization | done 2026-11-20 |
| Public visibility, secret scanning and push protection | author authorization | done 2026-11-20 |
| Zenodo enablement before the Release | author, in the Zenodo portal | done 2026-11-20 |
| Annotated tag `v0.1.0`, GitHub Release | author authorization | done 2026-11-20 00:16 UTC: Release "Version 0.1.0" |
| Public-site listing | author authorization | landing entry at <https://jeff-kline.github.io/>; Pages build and live HTML checked for title, blurb, repository link and version DOI before this record was pushed |
| Living-metadata update (this commit) | author authorization | pushed after the site listing was verified live |
