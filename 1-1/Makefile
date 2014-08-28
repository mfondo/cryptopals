CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=Base64.cpp Base64Test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Base64Test.out

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)