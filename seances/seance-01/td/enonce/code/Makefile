CXX ?= g++
CC ?= gcc
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic -fsanitize=address,undefined -g
CFLAGS ?= -std=c17 -Wall -Wextra -pedantic -fsanitize=address,undefined -g

CPP_PROGRAMS := 02-initialisation 03-references 04-signatures 05-const 06-nullptr
CPP_BINARIES := $(addprefix build/,$(CPP_PROGRAMS))

.PHONY: all clean diagnostics diagnostic-narrowing diagnostic-const-bind \
	diagnostic-const-write

all: build/01-c-vs-cpp $(CPP_BINARIES)

build:
	mkdir -p build

build/01-c-vs-cpp: 01-c-vs-cpp.c | build
	$(CC) $(CFLAGS) $< -o $@

build/%: %.cpp | build
	$(CXX) $(CXXFLAGS) $< -o $@

diagnostic-const-bind:
	$(CXX) $(CXXFLAGS) -DTRY_INVALID_CONST_BIND 05-const.cpp -o build/diagnostic-const-bind

diagnostic-const-write:
	$(CXX) $(CXXFLAGS) -DTRY_INVALID_CONST_WRITE 05-const.cpp -o build/diagnostic-const-write

diagnostic-narrowing:
	$(CXX) $(CXXFLAGS) -DTRY_NARROWING 02-initialisation.cpp -o build/diagnostic-narrowing

diagnostics:
	! $(MAKE) diagnostic-narrowing
	! $(MAKE) diagnostic-const-bind
	! $(MAKE) diagnostic-const-write

clean:
	rm -rf build
