#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "scanner.h"
#include "ErrorReporter/ErrorReporter.h"
using std::cout, std::endl, std::string, std::vector;

bool hadError = false;

// function declarations cause i dont want to use a header file for driver code and c++ doesn't support hoisting cause idk why
void report(int line, string where, string message);
void error(int line, string message);
void run(string source);
void runFile(string filePath);

void run(string source) {
    Scanner scanner = Scanner(source);
    vector<Token> tokens = scanner.scanTokens();
    // print tokens
    for(Token t : tokens) {
        cout << t.tokenToString() << endl;
    }
    error(scanner.getLine(), "Unexpected token");
}

void runFile(string filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "filePath " << filePath << " cannot be opened";
        return;
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    string source = buffer.str();
    cout << source;
    run(source);
    if(hadError) {
        exit(EXIT_FAILURE);
    };
}

void report(int line, string where, string message) {
    std::cerr << "[line " << line  << "] Error" << where << ": " << message << endl;
    hadError = true;
}

void error(int line, string message) {
    report(line, "", message);
}

int main(int argc, char* argv[]) {
    hadError = false;
    if (argc == 2) {
        runFile(argv[1]);
    }
    else {
        cout << "Usage: ./build/testScanner.o [filePath]" << endl;
        return -1;
    }
    return 0;
}