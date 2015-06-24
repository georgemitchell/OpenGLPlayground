RM := rm -rf

SRCDIR = ./src
OBJDIR = ./obj
BINDIR = ./bin
INCDIR = ./src

CC = clang++

EXEC = main
SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(OBJDIR)/main.o $(OBJDIR)shader.o

CXX_FLAGS = -I $(INCDIR) -c -g -Wall -Wextra

LDFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo


# All Target
all: directories playground

debug: CXX_FLAGS += -DDEBUG -g
debug: directories playground
	
directories: 
	mkdir -p $(OBJDIR)
	mkdir -p $(BINDIR)

# Tool invocations
playground: main.o shader.o
	@echo 'Building target: $@'
	@echo 'Invoking: MacOS X C++ Linker'
	g++ $(LDFLAGS) -lglfw3 -lGLEW -o $(BINDIR)/Playground $(OBJDIR)/main.o $(OBJDIR)/shader.o
	@echo 'Finished building target: $@'
	@echo ' '

main.o: $(SRCDIR)/main.cpp
	$(CC) $(CXX_FLAGS) -o $(OBJDIR)/main.o $(SRCDIR)/main.cpp

shader.o: $(SRCDIR)/shader.cpp
	$(CC) $(CXX_FLAGS) -o $(OBJDIR)/shader.o $(SRCDIR)/shader.cpp

clean:
	-$(RM) $(OBJDIR) $(BINDIR)
