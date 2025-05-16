# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Directories
BUILD_DIR = build
SRC_DIR = .

# Source files
SRCS = $(SRC_DIR)/token.cpp $(SRC_DIR)/scanner.cpp
OBJS = $(patsubst $(SRC_DUR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Executable Target
TARGET = $(BUILD_DIR)/testScanner

# Default Target
all: $(TARGET)

# Build testScanner executable
$(TARGET): $(OBJS) $(SRC_DIR)/testScanner.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile .cpp files into build/*.o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean