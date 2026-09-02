CXX = g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -pedantic

# Le préfixe peut être remplacé sur la ligne de commande si nécessaire :
# make GMSH_PREFIX=/chemin/vers/gmsh
GMSH_BIN ?= $(shell command -v gmsh)
GMSH_PREFIX ?= $(abspath $(dir $(GMSH_BIN))/..)
CPPFLAGS += -I$(GMSH_PREFIX)/include
LDFLAGS += -L$(GMSH_PREFIX)/lib -Wl,-rpath,$(GMSH_PREFIX)/lib
LDLIBS += -lgmsh

TARGET := mesh_demo
SOURCES := mesh_config.cpp gmsh_session.cpp gmsh_adapter.cpp main.cpp
OBJECTS := $(SOURCES:.cpp=.o)

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET) mesh.msh coarse.msh fine.msh
