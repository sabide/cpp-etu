CXX ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic -fsanitize=address,undefined -g

.PHONY: all clean run diagnostics

all: build/etape3 build/etape4

build:
	mkdir -p build

build/etape3: etape3_fonctions_libres/int_array.cpp \
		etape3_fonctions_libres/main.cpp \
		etape3_fonctions_libres/int_array.hpp | build
	$(CXX) $(CXXFLAGS) etape3_fonctions_libres/int_array.cpp \
		etape3_fonctions_libres/main.cpp -o $@

build/etape4: etape4_fonctions_membres/int_array.cpp \
		etape4_fonctions_membres/main.cpp \
		etape4_fonctions_membres/int_array.hpp | build
	$(CXX) $(CXXFLAGS) etape4_fonctions_membres/int_array.cpp \
		etape4_fonctions_membres/main.cpp -o $@

run: all
	./build/etape3
	./build/etape4

diagnostics: | build
	! $(CXX) $(CXXFLAGS) -c diagnostics/free_const_modification.cpp \
		-o build/free_const_modification.o
	! $(CXX) $(CXXFLAGS) -c diagnostics/member_const_modification.cpp \
		-o build/member_const_modification.o

clean:
	rm -rf build
