# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Default target
all: help

# Remove all object files and executables
clean:
	find . -type f -perm -u+x -exec rm -f {} +

# Compile and run a specific program
# % - target / output filename
# %.c - prerequisit - source file that mathes the target
# $@ - represents the target
# $< - represents the first prerequisit
# $(subst ./,,$@): Removes the leading ./ from the executable name if it exists. To ensures the executable path is formatted correctly.

%: %.c
	$(CC) $(CFLAGS) -o $@ $< && ./$(subst ./,,$@)

# Help message
help:
	@echo "Usage:"
	@echo " make <filename>     Compile and run a specific C program"
	@echo " make clean          Remove all object files and executables"
