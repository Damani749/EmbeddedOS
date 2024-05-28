# Makefile for running a shell script

# Define variables
SCRIPT_NAME := q4.sh

# Define targets and their dependencies
.PHONY: all run clean

# Default target
all: run

# Target to run the script
run: $(SCRIPT_NAME)
	@echo "Running $(SCRIPT_NAME)..."
	@chmod +x $(SCRIPT_NAME) && ./$(SCRIPT_NAME)

# Target to clean up
clean:
	@echo "Cleaning up..."
	@# Add any cleanup commands here if necessary

