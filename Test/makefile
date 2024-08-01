# Simple perceptron project
# Laura Kollmorgen
#
# Last updated: 8/1/24
#
# Directory Path: simple_perceptron/Test
#
# Makefile to run c++ tests of simple perceptron implementation
#
#
# GNU C++ Compiler
CPP         = g++    

# compiler flags -O3 optimized version
CPPFLAGS    = -O3 -o
CPP_LIBFLAGS=	-O3 -c

# allows for compiler warning messages
ERRORFLAG 	= -Wall

# The directory where library include files are stored.
INC_DIR = ../Include

# The directory where library object files are stored
LIB_DIR     = ../Lib

# Executable programs
BIN_DIR     = ../Bin

# Executables to test functionalities
EXECUTABLES = test_source_s_percept

# create perceptron class object file
test_source_s_percept: $(INC_DIR)/s_percept.h
	$(CPP) $(CPPFLAGS) test_source_s_percept test_source_s_percept.cpp \
	-I$(INC_DIR) $(LIB_DIR)/libpercept.a
	mv test_source_s_percept $(BIN_DIR)
	cd $(BIN_DIR); ./test_source_s_percept

all:
	make test_source_s_percept

clean:
	cd $(BIN_DIR); rm $(EXECUTABLES)
