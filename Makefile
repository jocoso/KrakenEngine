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
# ******************************************************

test: $(TESTDIR)/tester.o $(SOURCEDIR)/runner.o $(SOURCEDIR)/narrator.o $(SOURCEDIR)/scene.o $(SOURCEDIR)/general_book.o
		$(CC) $(CFLAGS) -o test $(TESTDIR)/tester.o $(SOURCEDIR)/runner.o $(SOURCEDIR)/narrator.o $(SOURCEDIR)/scene.o $(SOURCEDIR)/general_book.o

tester.o: $(TESTDIR)/tester.cpp $(INCLUDEDIR)/runner.h
		$(CC) $(CFLAGS) -c $(TESTDIR)/tester.cpp

runner.o: $(INCLUDEDIR)/runner.h
narrator.o: $(INCLUDEDIR)/narrator.h $(INCLUDEDIR)/scene.h
scene.o: $(INCLUDEDIR)/scene.h $(INCLUDEDIR)/rawr_object.h
action_book.o: $(INCLUDEDIR)/general_book.h  $(INCLUDEDIR)/action_book.h $(INCLUDEDIR)/scene.h

test-clean:
	$(RM) test.exe $(RM) test.exe.stackdump $(SOURCEDIR)/runner.o $(SOURCEDIR)/narrator.o $(SOURCEDIR)/scene.o $(TESTDIR)/tester.o $(SOURCEDIR)/general_book.o 

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
