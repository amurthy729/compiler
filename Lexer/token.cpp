#include "token.h"
#include "scanner.h"

string typeToString(TokenType type)
{
    switch (type) {
        // SINGLE CHARACTER TOKENS
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::LEFT_BRACE: return "LEFT_BRACE";
        case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
        case TokenType::COMMA: return "COMMA";
        case TokenType::DOT: return "DOT";
        case TokenType::MINUS: return "MINUS";
        case TokenType::PLUS: return "PLUS";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::SLASH: return "SLASH";
        case TokenType::STAR: return "STAR";

        // ONE OR TWO CHARACTER TOKENS
        case TokenType::BANG: return "BANG";
        case TokenType::BANG_EQUAL: return "BANG_EQUAL";
        case TokenType::EQUAL: return "EQUAL";
        case TokenType::EQUAL_EQUAL: return "EQUAL_EQUAL";
        case TokenType::GREATER: return "GREATER";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::LESS: return "LESS";
        case TokenType::LESS_EQUAL: return "LESS_EQUAL";

        // LITERALS
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::STRING: return "STRING";
        case TokenType::NUMBER: return "NUMBER";

        // KEYWORDS
        case TokenType::AND: return "AND";
        case TokenType::CLASS: return "CLASS";
        case TokenType::ELSE: return "ELSE";
        case TokenType::FALSE: return "FALSE";
        case TokenType::FUN: return "FUN";
        case TokenType::FOR: return "FOR";
        case TokenType::IF: return "IF";
        case TokenType::NIL: return "NIL";
        case TokenType::OR: return "OR";
        case TokenType::PRINT: return "PRINT";
        case TokenType::RETURN: return "RETURN";
        case TokenType::SUPER: return "SUPER";
        case TokenType::THIS: return "THIS";
        case TokenType::TRUE: return "TRUE";
        case TokenType::VAR: return "VAR";
        case TokenType::WHILE: return "WHILE";

        case TokenType::EoF: return "EOF";

        default: return "NONE";
    }
}

Token::Token() : type(TokenType::NONE), lexeme(""), literal(monostate{}), line(0) {}

Token::Token(TokenType type, string lexeme, variant<bool, int, float, string, monostate> literal, int line) : type(type), lexeme(lexeme), literal(literal), line(line) {}

string Token::getLexeme()
{
    return this->lexeme;
}

variant<bool, int, float, string, monostate> Token::getLiteral()
{
    return this->literal;
}

int Token::getLine()
{
    return this->line;
}
string Token::tokenToString()
{
    string lit;
    if(std::holds_alternative<string>(literal)) {
        lit = std::get<string>(literal);
    }
    else if (std::holds_alternative<int>(literal)){
        lit = std::to_string(std::get<int>(literal));
    }
    else if (std::holds_alternative<float>(literal)) {
        lit = std::to_string(std::get<float>(literal));
    }
    else if (std::holds_alternative<bool>(literal)) {
        lit = std::to_string(std::get<bool>(literal));
    }
    else {
        lit = "nil";
    }
    return typeToString(type) + " " + this->lexeme + " " + lit;
}
