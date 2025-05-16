#include "scanner.h"

Scanner::Scanner(string source) : source(source) {}

vector<Token> Scanner::scanTokens()
{
    return vector<Token>();
}

bool Scanner::isAtEnd()
{
    return (long unsigned int) current >= source.length();
}