CC := gcc
CFLAGS ?= -std=c17 -Wall -Wextra -pedantic -g
CXX := g++
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
C_DEMO = build/c_vs_cpp_c

.PHONY: all run slide-02 error-narrowing error-const error-signature clean

all: $(C_DEMO) $(BINARIES)

$(C_DEMO): c_vs_cpp.c
	@mkdir -p build
	$(CC) $(CFLAGS) $< -o $@

build/%: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) $< -o $@

run: all
	@echo "--- $(C_DEMO) ---"; "$(C_DEMO)"
	@set -e; for demo in $(BINARIES); do \
		echo "--- $$demo ---"; "$$demo"; \
	done

slide-02: $(C_DEMO)
	@echo "Compilation C acceptée : $(C_DEMO)"
	@echo "Compilation du même programme en C++ (refus attendu) :"
	@if $(CXX) $(CXXFLAGS) c_vs_cpp.cpp -o build/c_vs_cpp_cpp; then \
		echo "Erreur : la compilation C++ aurait dû être refusée."; \
		rm -f build/c_vs_cpp_cpp; exit 1; \
	else echo "Compilation C++ refusée comme attendu."; fi

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
