# === Compiler settings ===
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I. -ILexer -IErrorReporter

# === Directory setup ===
OBJ_DIR = build
BIN_DIR = build

# === Source files ===
LEXER_SRC = Lexer/scanner.cpp Lexer/token.cpp
ERROR_SRC = ErrorReporter/ErrorReporter.cpp
SCANNER_TEST_SRC = Lexer/test/testScanner.cpp

# === Object files ===
LEXER_OBJ = $(LEXER_SRC:%.cpp=$(OBJ_DIR)/%.o)
ERROR_OBJ = $(ERROR_SRC:%.cpp=$(OBJ_DIR)/%.o)
SCANNER_TEST_OBJ = $(OBJ_DIR)/Lexer/test/testScanner.o

# === Executables ===
SCANNER_BIN = $(BIN_DIR)/testScanner

# === Default target ===
all: $(SCANNER_BIN)

# === Link final binary ===
$(SCANNER_BIN): $(SCANNER_TEST_OBJ) $(LEXER_OBJ) $(ERROR_OBJ)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# === Compile .cpp -> .o ===
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# === Clean up ===
clean:
	rm -rf $(OBJ_DIR)
