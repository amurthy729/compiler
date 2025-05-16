#ifndef SCANNER_H
#define SCANNER_H

#include "token.h"
#include <vector>

using std::vector;

class Scanner {
    private:
    const string source;
    const vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;

    public:
    Scanner(string source);
    vector<Token> scanTokens();
    bool isAtEnd();
};

#endif