# Simple perceptron project
# Laura Kollmorgen
#
# Last updated: 7/29/24
#
# Directory Path: simple_perceptron/Source
# Adapted from: 
# https://github.com/lkollmorgen/Cellular-Automata-Library/blob/main/Source/Makefile
#
# Makefile to run simple perceptron implementation
#
#
# GNU C++ Compiler
CPP         = g++      
CPP_LIBFLAGS=	-O3 -c

# The directory where the main library include files are stored.
INC_DIR = ../Include

# The directory where the main library object files are stored
LIB_DIR     = ../Lib

# The object files and libraries generated from the makefile
PERCEPT_OBJS = source_s_percept.o
PERCEPT_LIB = libpercept.a

# create perceptron class object file
source_s_percept.o: 
	$(CPP) $(CPP_LIBFLAGS) source_s_percept.cpp -I$(INC_DIR)

#create+update perceptron class library. Move to /Lib
libpercept.a: $(PERCEPT_OBJS)
	ar -ru $(PERCEPT_LIB) $(PERCEPT_OBJS)
	mv $(PERCEPT_LIB) $(LIB_DIR)
	rm $(PERCEPT_OBJS)

all:
	make source_s_percept.o
	make libpercept.a

