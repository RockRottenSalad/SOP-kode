
CC = clang
DEBUG_CFLAGS = -m64 -g -Wall -Werror
RELEASE_CFLAGS = -m64 -O3 -Wall -Werror

LD_FLAGS = -lglfw3 -lGL -lpthread -lm -lX11
WINDOWS_LD_FLAGS = -lglfw3 -lkernel32 -lopengl32 -lm -luser32 -lshell32

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
	rm -f $(BINDIR)/main*
	$(CC) $(OBJDIR)/*.o -o $(BINDIR)/main $(LD_FLAGS)

windows_build:
	rm -f $(BINDIR)/main*
	$(CC) $(OBJDIR)/*.o -o $(BINDIR)/main.exe $(WINDOWS_LD_FLAGS)

run:
	./$(BINDIR)/main*

clean:
	rm -f $(OBJDIR)/*.o
