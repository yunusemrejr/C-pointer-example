# Makefile for C Pointer Demonstration Tool
# Author: YUNUS EMRE VURGUN
# License: MIT

# Compiler settings
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Wpedantic -O2
DEBUG_FLAGS = -g -DDEBUG
TARGET = pointer_demo
SOURCE = main.c

# Colors for output
COLOR_RESET = \033[0m
COLOR_GREEN = \033[32m
COLOR_YELLOW = \033[33m
COLOR_BLUE = \033[34m

# Default target
.PHONY: all
all: $(TARGET)
	@echo "$(COLOR_GREEN)✓ Build successful!$(COLOR_RESET)"
	@echo "$(COLOR_BLUE)Run with: ./$(TARGET)$(COLOR_RESET)"

# Build the main executable
$(TARGET): $(SOURCE)
	@echo "$(COLOR_YELLOW)Compiling $(SOURCE)...$(COLOR_RESET)"
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCE)

# Debug build
.PHONY: debug
debug: CFLAGS += $(DEBUG_FLAGS)
debug: clean $(TARGET)
	@echo "$(COLOR_GREEN)✓ Debug build complete!$(COLOR_RESET)"

# Clean build artifacts
.PHONY: clean
clean:
	@echo "$(COLOR_YELLOW)Cleaning build artifacts...$(COLOR_RESET)"
	rm -f $(TARGET)
	@echo "$(COLOR_GREEN)✓ Clean complete!$(COLOR_RESET)"

# Rebuild from scratch
.PHONY: rebuild
rebuild: clean all

# Run the program
.PHONY: run
run: all
	@echo "$(COLOR_BLUE)Running $(TARGET)...$(COLOR_RESET)"
	@echo ""
	./$(TARGET)

# Check for memory leaks (requires valgrind)
.PHONY: memcheck
memcheck: debug
	@echo "$(COLOR_YELLOW)Running memory check...$(COLOR_RESET)"
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET)

# Display help
.PHONY: help
help:
	@echo "$(COLOR_BLUE)C Pointer Demonstration Tool - Makefile$(COLOR_RESET)"
	@echo ""
	@echo "Available targets:"
	@echo "  $(COLOR_GREEN)make$(COLOR_RESET) or $(COLOR_GREEN)make all$(COLOR_RESET)     - Build the application"
	@echo "  $(COLOR_GREEN)make debug$(COLOR_RESET)           - Build with debug symbols"
	@echo "  $(COLOR_GREEN)make clean$(COLOR_RESET)           - Remove compiled files"
	@echo "  $(COLOR_GREEN)make rebuild$(COLOR_RESET)         - Clean and rebuild"
	@echo "  $(COLOR_GREEN)make run$(COLOR_RESET)             - Build and run the application"
	@echo "  $(COLOR_GREEN)make memcheck$(COLOR_RESET)        - Run with valgrind (requires valgrind)"
	@echo "  $(COLOR_GREEN)make help$(COLOR_RESET)            - Display this help message"
	@echo ""
