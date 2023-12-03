# Compiler and flags
CC = avr-gcc
CFLAGS =-mmcu=atmega32 -DF_CPU=8000000 -std=gnu99 -O2 -Wall -L.\lib -o $@ $^
INCA = ../inc ../lib
INCAA = $(wildcard $(INCA)/*.h)
# Source files and target
SRC = main.c
 # List the C source file here
# List all header files here
TARGET = main_hex

# Build the target
$(TARGET): $(SRC) $(INCAA)
	$(CC) $(CFLAGS) $< -o $@

# Clean up compiled files
clean:
	del *.o