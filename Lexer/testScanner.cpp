#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "scanner.h"
using std::cout, std::endl, std::string, std::vector;

bool hadError = false;

void run(string source) {
    Scanner scanner = Scanner(source);
    vector<Token> tokens = scanner.scanTokens();

    // print tokens
    for(Token t : tokens) {
        cout << t.tokenToString() << endl;
    }
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
}

void error(int line, string message) {
    report(line, "", message);
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        runFile(argv[1]);
    }
    else {
        cout << "Usage: ./testScanner [filePath]" << endl;
        return -1;
    }
    return 0;
}