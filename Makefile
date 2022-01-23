# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
CC = g++
# Debugging info
CFLAGS = -g -Wall
# ******************************************************


# Exec
main: tester.o runner.o
		$(CC) $(CFLAGS) -o main tester.o runner.o

tester.o: tester.cpp runner.h
		$(CC) $(CFLAGS) -c tester.cpp

runner.o: runner.h 

clean:
	$(RM) main runner.o tester.o
