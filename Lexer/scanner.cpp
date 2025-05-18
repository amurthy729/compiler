#include "scanner.h"
#include <stdexcept>

Scanner::Scanner(string source) : source(source) {}

vector<Token> Scanner::scanTokens()
{
    while(!isAtEnd()) {
        start = current;
        scanToken();
    }
    tokens.push_back(Token(TokenType::EoF, "", std::monostate{}, line));
    return tokens;
}

bool Scanner::isAtEnd()
{
    return (long unsigned int) current >= source.length();
}

void Scanner::scanToken()
{
    char c = advance();
    switch (c) {
        case '(': addToken(TokenType::LEFT_PAREN); break;
        case ')': addToken(TokenType::RIGHT_PAREN); break;
        case '{': addToken(TokenType::LEFT_BRACE); break;
        case '}': addToken(TokenType::RIGHT_BRACE); break;
        case ',': addToken(TokenType::COMMA); break;
        case '.': addToken(TokenType::DOT); break;
        case '-': addToken(TokenType::MINUS); break;
        case '+': addToken(TokenType::PLUS); break;
        case ';': addToken(TokenType::SEMICOLON); break;
        case '*': addToken(TokenType::STAR); break;

        default: 
        throw(std::runtime_error("Unexpected character.")); break;
    }
}

char Scanner::advance()
{
    return source.at(current++); // this consumes because we increment
}

void Scanner::addToken(TokenType type)
{
    addToken(type, std::monostate{});
}

void Scanner::addToken(TokenType type, std::variant<bool, int, float, string, monostate> literal)
{
    string text = source.substr(start, current);
    tokens.push_back(Token(type, text, literal, line));
}

int Scanner::getCurrent()
{
    return this->current;
}

int Scanner::getLine()
{
    return this->line;
}