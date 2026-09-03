CXX ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic -fsanitize=address,undefined -g

.PHONY: all run diagnostics diagnostic-copy diagnostic-assignment \
	diagnostic-private clean

all: int_array

int_array: int_array.cpp main.cpp int_array.hpp
	$(CXX) $(CXXFLAGS) int_array.cpp main.cpp -o $@

run: int_array
	./int_array

diagnostics: diagnostic-copy diagnostic-assignment diagnostic-private

diagnostic-copy:
	@if $(CXX) $(CXXFLAGS) int_array.cpp diagnostics/copie_interdite.cpp -o /tmp/td3-copy 2>/tmp/td3-copy.err; then \
		echo "ERREUR : la copie aurait dû être refusée"; exit 1; \
	else \
		echo "OK : le constructeur de copie est supprimé"; \
	fi

diagnostic-assignment:
	@if $(CXX) $(CXXFLAGS) int_array.cpp diagnostics/affectation_interdite.cpp -o /tmp/td3-assignment 2>/tmp/td3-assignment.err; then \
		echo "ERREUR : l'affectation aurait dû être refusée"; exit 1; \
	else \
		echo "OK : l'affectation par copie est supprimée"; \
	fi

diagnostic-private:
	@if $(CXX) $(CXXFLAGS) int_array.cpp diagnostics/acces_prive.cpp -o /tmp/td3-private 2>/tmp/td3-private.err; then \
		echo "ERREUR : l'accès privé aurait dû être refusé"; exit 1; \
	else \
		echo "OK : la représentation privée est inaccessible"; \
	fi

clean:
	$(RM) int_array
	$(RM) -r int_array.dSYM
