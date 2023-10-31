CC = g++
SDIR = game
OUT = bin/Snake
lflags = -lSDL2

make:
	$(CC) -o $(OUT) $(SDIR)/*.cpp $(lflags)
