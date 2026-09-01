CXX ?= g++
CC ?= gcc
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic -fsanitize=address,undefined -g
CFLAGS ?= -std=c17 -Wall -Wextra -pedantic -fsanitize=address,undefined -g

CPP_SOURCES := ex1_new.cpp ex1_vector.cpp ex2_initialisation.cpp \
	ex3_references.cpp ex3_reference_return.cpp ex4_parametres.cpp \
	ex5_const.cpp ex6_nullptr.cpp
CPP_BINARIES := $(addprefix build/,$(CPP_SOURCES:.cpp=))

.PHONY: all clean run diagnostics

all: build/ex1_c $(CPP_BINARIES)

build:
	mkdir -p build

build/ex1_c: ex1_c.c | build
	$(CC) $(CFLAGS) $< -o $@

build/%: %.cpp | build
	$(CXX) $(CXXFLAGS) $< -o $@

run: all
	./build/ex1_c
	./build/ex1_new
	./build/ex1_vector
	printf '4 10\n' | ./build/ex2_initialisation
	./build/ex3_references
	./build/ex3_reference_return
	./build/ex4_parametres
	./build/ex5_const
	./build/ex6_nullptr

diagnostics: | build
	! $(CXX) $(CXXFLAGS) diagnostics/ex1_c_as_cpp.cpp -o build/diagnostic-ex1
	! $(CXX) $(CXXFLAGS) diagnostics/ex2_narrowing.cpp -o build/diagnostic-ex2
	! $(CXX) $(CXXFLAGS) diagnostics/ex5_bind_const.cpp -o build/diagnostic-ex5-bind
	! $(CXX) $(CXXFLAGS) diagnostics/ex5_modify_const_ref.cpp -o build/diagnostic-ex5-write

clean:
	rm -rf build
