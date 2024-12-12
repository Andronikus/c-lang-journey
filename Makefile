# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
CPPCHECK = cppcheck

# PHONY targets
.PHONY: clean help cppcheck

# Default target
all: help

# Remove all object files and executables
clean:
	find . -type f -perm -u+x -exec rm -f {} +

cppcheck:
	$(CPPCHECK) --quiet --std=c99 --error-exitcode=1 --enable=all --suppress=missingIncludeSystem src/

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
	@echo " make cppcheck       Static analysis"
	@echo " make clean          Remove all object files and executables"
