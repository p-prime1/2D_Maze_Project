#Compiler
CC = gcc

#Compiler flags
CFLAGS = -Wall -Werror -Wextra -pedantic $(shell sdl2-config --cflags)

#Libraries to link with
LIBS = $(shell sdl2-config --libs) -lSDL2_image

#Linker flags
LDFLAGS = $(shell sdl2-config --libs)

#Target executable
TARGET = Run_Maze

#Find all .c files in the current directory
SRCS = $(wildcard *.c)

#Conver .c files to .o files
OBJS = $(SRCS:.c=.o)

#Default rule: build the target
all: $(TARGET)

#Rule to link the object files into the final executable
$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

#Rule to copile source files into object files
%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

#Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)
