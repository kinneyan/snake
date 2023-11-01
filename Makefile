CC = g++
SDIR = game
ODIR = bin
OUT = Snake
lflags = -lSDL2

make:
	$(CC) -o $(ODIR)/$(OUT) $(SDIR)/*.cpp $(lflags)

.PHONY: run
run: make
	./$(ODIR)/$(OUT)

.PHONY: clean
clean:
	rm $(ODIR)/*
