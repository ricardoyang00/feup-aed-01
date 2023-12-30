# Set g++ as the C++ compiler
CXX = g++

# C++ source files to consider in compilation for all programs
COMMON_CPP_FILES = src/Data.cpp src/ReadData.cpp src/UtilityFunctions.cpp src/Consult.cpp src/Script.cpp src/Change.cpp

# Your target program
PROGRAMS = run

# Doxygen configuration file
DOXYGEN_CONFIG = docs/Doxyfile

# Target directory for Doxygen documentation
DOXYGEN_INPUT_DIR = docs
DOXYGEN_OUTPUT_DIR = docs/documentation

# Target for Doxygen documentation
DOXYGEN_TARGET = $(DOXYGEN_OUTPUT_DIR)/html/index.html

all: $(PROGRAMS)

run: $(COMMON_CPP_FILES) src/runscript.cpp
	$(CXX) -o run src/runscript.cpp $(COMMON_CPP_FILES)

doxygen: $(DOXYGEN_CONFIG)
	doxygen $<