CXX ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic -g

DEMOS = \
	01-surcharge \
	02-resolution-surcharge \
	03-string-copie-comparaison \
	04-passerelle-c-string \
	05-nullptr \
	06-ressource-manuelle-et-vector \
	07-fonctions-membres \
	08-invariant-public \
	09-copie-du-pointeur

BINARIES = $(addprefix build/,$(DEMOS))

.PHONY: all run error-ambiguous clean

all: $(BINARIES)

build/%: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $< -o $@

run: all
	@set -e; for demo in $(BINARIES); do \
		echo "--- $$demo ---"; "$$demo"; \
	done

error-ambiguous:
	@if $(CXX) $(CXXFLAGS) -DTRY_AMBIGUOUS -fsyntax-only 02-resolution-surcharge.cpp; then \
		echo "Erreur : la compilation aurait dû être refusée."; exit 1; \
	else echo "Compilation refusée comme attendu."; fi

clean:
	rm -rf build
