# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation
CC = g++
# Debugging info
CFLAGS = -g -Wall

PROJDIR := $(realpath $(CURDIR))
INCLUDEDIR := $(PROJDIR)/include
SOURCEDIR := $(PROJDIR)/src
TESTDIR := $(PROJDIR)/test
LIBDIR := $(PROJDIR)/lib

TARGET = main.exe 

SOURCES = $(foreach dir,$(SOURCEDIR),$(wildcard $(dir)/*.c))
OBJS := $(subst $(SOURCEDIR),$(LIBDIR),$(SOURCES:.c=.o))
DEPS = $(OBJS:.o=.d)
EXEC = ./
# ******************************************************

#! Test runner
test: $(TESTDIR)/test_window_open.o $(SOURCEDIR)/runner.o
		$(CC) $(CFLAGS) -o test1 $(TESTDIR)/test_window_open.o $(SOURCEDIR)/runner.o

#! Test Object
test_window_open.o: $(TESTDIR)/test_window_open.cpp $(INCLUDEDIR)/runner.h
		$(CC) $(CFLAGS) -c $(TESTDIR)/test_window_open.cpp

# Libraries
runner.o: $(INCLUDEDIR)/runner.h

test-clean:
	$(RM) test1.exe $(RM) test.exe.stackdump $(SOURCEDIR)/runner.o $(TESTDIR)/test_window_open.o

# # Exec
# main: tester.o runner.o
# 		$(CC) $(CFLAGS) -o main tester.o runner.o

# test: ./test/tester.o ./include/runner.o
# 		$(CC) $(CFLAGS) -o test ./test/tester.o ./include/runner.o

# tester.o: ./test/tester.cpp ./include/runner.h
# 		$(CC) $(CFLAGS) -c ./test/tester.cpp

# ./include/runner.o: ./include/runner.h 
# 		$(CC) $(CFLAGS) -c ./include/runner.h

# clean:
# 	$(RM) main ./include/runner.o ./test/tester.o
