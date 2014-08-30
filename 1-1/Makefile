CC=g++
CFLAGS=-c -Wall -g
LDFLAGS=
#SOURCES=Base64.cpp Base64Test.cpp TODO dumb to do this - figure out how to do multiple main methods
#SOURCES=Hex.cpp HexTest.cpp TODO
SOURCES=Base64.cpp Hex.cpp Challenge_1_1.cpp
OBJECTS=$(SOURCES:.cpp=.o)
#EXECUTABLE=Base64Test.out TODO dumb to do this - figure out how to do multiple main methods
#EXECUTABLE=HexTest.out TODO
EXECUTABLE=Challenge_1_1.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)