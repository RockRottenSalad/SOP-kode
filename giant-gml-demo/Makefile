
CC = clang
DEBUG_CFLAGS = -m64 -g -Wall -Wpedantic
RELEASE_CFLAGS = -m64 -O3 -Wall -Wpedantic

LD_FLAGS = -lX11 -lglfw3 -lGL -lpthread -lXrandr -lXi -ldl -lm

OBJDIR = obj
INCLUDEDIR = lib
SRCDIR  = $(wildcard src/**/*.c) $(wildcard src/*.c)

BINDIR = bin


debug:
	$(CC) -c $(SRCDIR) $(DEBUG_CFLAGS) -I $(INCLUDEDIR)
	mv *.o $(OBJDIR)

release:
	$(CC) -c $(SRCDIR) $(RELEASE_CFLAGS) -I $(INCLUDEDIR)
	mv *.o $(OBJDIR)

build:
	$(CC) $(OBJDIR)/*.o -o $(BINDIR)/main $(LD_FLAGS)

run:
	./$(BINDIR)/main

clean:
	rm -f $(OBJDIR)/*.o
