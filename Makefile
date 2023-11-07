CC = g++
CFLAGS = -Wall
LIBS = -lSDL2
SOURCES = $(wildcard game/*.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))
EXECUTABLE = bin/Snake

all:	build $(EXECUTABLE)

$(OBJECTS): game/%.o: game/%.cpp
	$(CC) $(CFLAGS) -c $< $(LIBS) -o $@

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

win: CC = x86_64-w64-mingw32-g++
win: CFLAGS = -Wall -mwindows -static-libgcc -static-libstdc++
win: all

build:
	@mkdir -p bin

.PHONY: run
run: all
	./$(EXECUTABLE)

.PHONY: clean
clean:
	rm -r $(EXECUTABLE) $(OBJECTS) bin
