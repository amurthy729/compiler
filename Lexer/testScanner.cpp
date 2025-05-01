#include <iostream>
#include <string>
#include "scanner.h"
using std::cout, std::endl, std::string;



void runFile(string file) {
    cout << file << endl;
}

void runPrompt() {
    cout << "Prompt" << endl;
}

int main(int argc, char* argv[]) {
    if (argc > 2) {
        cout << "Usage: [script]" << endl;
    }
    else if (argc == 2) {
        runFile(argv[1]);
    }
    else {
        runPrompt();
    }
}