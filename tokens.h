//
// Created by remy on 12/1/22.
//

#ifndef LEXERCPP_TOKENS_H
#define LEXERCPP_TOKENS_H

#include <string>

enum TokenType {
    Indentifier,
    Equal,
    String,
    Number,
    Semicolon
};

class IToken {
public:
    TokenType m_type;

    IToken(TokenType type);

    virtual std::string to_string() = 0;
};

class TokenIdentifier: public IToken {
public:
    std::string m_value;

    TokenIdentifier(std::string& value);

    std::string to_string() override;
};

class TokenEqual: public IToken {
public:
    TokenEqual();

    std::string to_string() override;
};

class TokenString: public IToken {
public:
    std::string m_value;

    TokenString(std::string& value);

    std::string to_string() override;
};

class TokenNumber: public IToken {
public:
    std::string m_value;

    TokenNumber(std::string& value);

    std::string to_string() override;
};

class TokenSemicolon: public IToken {
public:
    TokenSemicolon();

    std::string to_string() override;
};

#endif //LEXERCPP_TOKENS_H
