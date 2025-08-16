# Directories
BUILD_DIR = build
TARGET_EXEC = main

# VPATH tells make where to look for source files.
VPATH = src lib/src

# Find all .c files in the VPATH directories
SRC_FILES = $(foreach dir,$(VPATH),$(wildcard $(dir)/*.c))

# Create a list of object files in the build directory
OBJ_FILES = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC_FILES:.c=.o)))

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -O0 -Ilib/src -pthread
LDFLAGS = -pthread

# Default target
all: $(TARGET_EXEC)

# Link the executable
$(TARGET_EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ $(LDFLAGS)

# Compile source files into object files
$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET_EXEC)
.PHONY: all clean
