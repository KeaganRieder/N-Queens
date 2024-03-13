# Makefile for  missionaries and cannibals problem solver program 

# programs and their associated classes
PROGRAM_NAME = NQueenSolver

CLASS = Board
MAIN = NQueenSolver

#compiler info
CC=g++
CC_VERSION= -std=c++11
CC_FLAGS= $(CC_VERSION) -Wall

#files for Projects
# OBJS = $(CLASS).0 $(CLASS2).0 $(MAIN).0 $(PROGRAM_NAME).0

# Default goal
.DEFAULT_GOAL := all

all: $(PROGRAM_NAME) 

$(PROGRAM_NAME): $(CLASS).o $(MAIN).o 
	$(CC) $(CFLAGS) -o $(PROGRAM_NAME) $(CLASS).o  $(MAIN).o

# making class 1
$(CLASS).o: $(CLASS).cpp $(CLASS).h
	$(CC) $(CFLAGS) -c $(CLASS).cpp


# making main
$(MAIN).o: $(MAIN).cpp $(CLASS).h 
	$(CC) $(CFLAGS) -c $(MAIN).cpp

#clean targets  
cleanLinix:
	rm -rf *.o *.exe
	
cleanWin:
	del *.o *.exe


	
