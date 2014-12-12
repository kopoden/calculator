CC=g++
CFLAGS=-c -Wall
HEADERS=calc.h stack_functions.h
SOURCES=main.cpp calc.cpp stack_functions.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=calc

all: $(HEADERS) $(SOURCES) $(EXECUTABLE)

MakeObjects: $(HEADERS) $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES)

$(EXECUTABLE): $(OBJECTS) MakeObjects
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

clean:
	rm -f *.o
