#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <variant>
using std::string, std::variant, std::monostate;

enum class TokenType {
    // SINGLE CHARACTER TOKENS
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE, COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // ONE OR TWO CHARACTER TOKENS
    BANG, BANG_EQUAL, EQUAL, EQUAL_EQUAL, GREATER, GREATER_EQUAL, LESS, LESS_EQUAL,

    // LITERALS
    IDENTIFIER, STRING, NUMBER,

    // KEYWORDS
    AND, CLASS, ELSE, FALSE, FUN, FOR, IF, NIL, OR, PRINT, RETURN, SUPER, THIS, TRUE, VAR, WHILE,

    // NONE
    NONE,

    EoF
};

string typeToString(TokenType type);

class Token {
    private:
    const TokenType type;
    const string lexeme;
    const variant<int, double, string, monostate> literal;
    const int line;
    /*
    * A longer discussion about void* literal
    * When we are creating a token, we do not know if there is a literal value until we know the token type
    * Even if we do know the type, the literal value is obviously dependent on the lexeme
    * Hence, we need to use void* and pass in a pointer to the memory because we will know what type it is when we are instantiating the object
    */

    public:
    Token(); // default constructor. if this is ever called, i fucked up somewhere.
    Token(TokenType type, string lexeme, variant<int, double, string, monostate> literal, int line); // parameterized constructor
    TokenType getType();
    string getLexeme();
    void* getLiteral();
    int getLine();

    string tokenToString();

};

#endif