# WGE Makefile

# COMPILER & FLAGS
CC      = g++
CFLAGS  = -g -Wall -Wextra -std=c++17 -pedantic

#  DEFINITIONS
# Directories
BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src

# Executable
BIN     = $(BIN_DIR)/GAME

# Source files
SRC     = $(wildcard $(SRC_DIR)/*.cpp)

# [ Object files ]
OBJ     = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Libraries links
SFML    = -lsfml-graphics -lsfml-window -lsfml-system 
# MATH = -lm


# RULES
all: $(BIN)

# Executable linkage from object files
$(BIN): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(SFML)

# Objects separated compilation
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(SFML)

clean:
	rm -f $(BIN_DIR)/* $(OBJ_DIR)/*

#-------------------------------------------------
