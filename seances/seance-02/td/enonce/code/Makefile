CXX ?= g++
CC ?= gcc
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic -fsanitize=address,undefined -g
CFLAGS ?= -std=c17 -Wall -Wextra -pedantic -fsanitize=address,undefined -g

.PHONY: all clean run

all: build/int_array_c build/int_array_cpp

build:
	mkdir -p build

build/int_array_c: int_array_c.c main_c.c int_array_c.h | build
	$(CC) $(CFLAGS) int_array_c.c main_c.c -o $@

build/int_array_cpp: int_array.cpp main.cpp int_array.hpp | build
	$(CXX) $(CXXFLAGS) int_array.cpp main.cpp -o $@

run: all
	./build/int_array_c
	./build/int_array_cpp

clean:
	rm -rf build
