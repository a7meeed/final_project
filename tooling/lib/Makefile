# Compiler and flags
CC = avr-gcc
CFLAGS = -Wall
INCA = ../inc 
INCAA = $(wildcard $(INCA)/*.h)
# Source files and target
SRC = DIO_program.o
 # List the C source file here
HEADERS =  DIO_config.h DIO_interface.h DIO_private.h DIO_register.h
# List all header files here
TARGET = DIO_driver

# Build the target
$(TARGET): $(SRC) $(HEADERS) $(INCAA)
	$(CC) $(CFLAGS) $< -o $@

# Clean up compiled files
clean:
	del *.o