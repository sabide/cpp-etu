CXX ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic -fsanitize=address,undefined -g

SOURCES := element.cpp triangle.cpp quadrilateral.cpp report.cpp main.cpp
TARGET := td6

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
