SHELL := /bin/sh
CC ?= cc
CXX ?= c++

PDFLATEX ?= pdflatex
export SOURCE_DATE_EPOCH := 1795132800
export FORCE_SOURCE_DATE := 1

.PHONY: paper verify

# Three passes from a clean extraction; no inherited auxiliaries are required.
paper:
	cd paper && $(PDFLATEX) -interaction=nonstopmode -halt-on-error main.tex >/dev/null
	cd paper && $(PDFLATEX) -interaction=nonstopmode -halt-on-error main.tex >/dev/null
	cd paper && $(PDFLATEX) -interaction=nonstopmode -halt-on-error main.tex >/dev/null
	@! grep -E 'Warning:|Overfull|undefined references|undefined citations' paper/main.log
	@echo "paper built: paper/main.pdf"

# Build and check the matrix (about ten seconds on one core) and compare each
# output with the pinned copy in evidence/.
verify:
	@rm -rf build/certificates
	@CC="$(CC)" CXX="$(CXX)" sh code/run-certificates.sh build/certificates
	@for f in evidence/*.txt; do \
	  if cmp -s "$$f" "build/certificates/$${f#evidence/}"; then echo "MATCH $${f#evidence/}"; \
	  else echo "MISMATCH $${f#evidence/}"; exit 1; fi; done
	@echo "verify: all certificate outputs match evidence/"
