# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -std=c++11 -g -Wall -o
# the build target executable:
TARGET = main
edit: main.o

main.o: main.cpp
	$(CC) $(CFLAGS) dynamic $(TARGET).cpp
all: $(TARGET)
	$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o dynamic $(TARGET).cpp

clean:
	$(RM) $(TARGET)
