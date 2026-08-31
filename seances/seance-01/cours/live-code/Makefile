CXX ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic -g

DEMOS = \
	01-initialisation-accolades \
	02-const-fait-verifier \
	03-pointeur-ou-reference \
	04-reference-alias \
	05-signatures-expriment-intention \
	06-diagnostic-signature \
	07-int-array-signatures

BINARIES = $(addprefix build/,$(DEMOS))

.PHONY: all run error-narrowing error-const error-signature clean

all: $(BINARIES)

build/%: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $< -o $@

run: all
	@set -e; for demo in $(BINARIES); do \
		echo "--- $$demo ---"; "$$demo"; \
	done

error-narrowing:
	@if $(CXX) $(CXXFLAGS) -DTRY_NARROWING -fsyntax-only 01-initialisation-accolades.cpp; then \
		echo "Erreur : la compilation aurait dû être refusée."; exit 1; \
	else echo "Compilation refusée comme attendu."; fi

error-const:
	@if $(CXX) $(CXXFLAGS) -DTRY_MODIFY_CONST -fsyntax-only 02-const-fait-verifier.cpp; then \
		echo "Erreur : la compilation aurait dû être refusée."; exit 1; \
	else echo "Compilation refusée comme attendu."; fi

error-signature:
	@if $(CXX) $(CXXFLAGS) -DTRY_MODIFY_READ_ONLY -fsyntax-only 06-diagnostic-signature.cpp; then \
		echo "Erreur : la compilation aurait dû être refusée."; exit 1; \
	else echo "Compilation refusée comme attendu."; fi

clean:
	rm -rf build
