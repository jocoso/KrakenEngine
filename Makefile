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

# TARGET = tester

# runner.o: runner.cpp runner.h
# 		$(CC) $(CFLAGS) -o runner.cpp


# all: $(TARGET) runner.o

# $(TARGET): $(TARGET).cpp
# 		$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp runner.o

# clean:
# 	$(RM) $(TARGET)