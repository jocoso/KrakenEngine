CXX = $(shell wx-config --cxx)

PROGRAM = main
OBJECTS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

# implementation

.SUFFIXES: .o .cpp

.cpp.o: $(CXX) -x `wx-config --cxxflags` -o $@ $<

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `wx-config --libs`

clean:
	rm -f *.o $(PROGRAM)