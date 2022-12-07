//
// Created by remy on 12/1/22.
//

#include "tokens.h"

////////////////////////////////////////////////////////////////////////////////////////
//                                       IToken                                       //
////////////////////////////////////////////////////////////////////////////////////////

IToken::IToken(TokenType type) : m_type(type) {}

////////////////////////////////////////////////////////////////////////////////////////
//                                  Token Identifier                                  //
////////////////////////////////////////////////////////////////////////////////////////

TokenIdentifier::TokenIdentifier(std::string& value) : IToken(TokenType::Indentifier), m_value(value) {}

std::string TokenIdentifier::to_string() {
    auto str = std::string();

    str.append("Identifier(");
    str.append(this->m_value);
    str.push_back(')');

    return str;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                     Token Equal                                    //
////////////////////////////////////////////////////////////////////////////////////////

TokenEqual::TokenEqual() : IToken(TokenType::Equal) {}

std::string TokenEqual::to_string() {
    auto str = std::string();

    str.append("Equal [=]");

    return str;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                    Token String                                    //
////////////////////////////////////////////////////////////////////////////////////////

TokenString::TokenString(std::string& value) : IToken(TokenType::String), m_value(value) {}

std::string TokenString::to_string() {
    auto str = std::string();

    str.append("String(");
    str.append(this->m_value);
    str.push_back(')');

    return str;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                    Token Number                                    //
////////////////////////////////////////////////////////////////////////////////////////

TokenNumber::TokenNumber(std::string& value) : IToken(TokenType::Number), m_value(value) {}

std::string TokenNumber::to_string() {
    auto str = std::string();

    str.append("Number(");
    str.append(this->m_value);
    str.push_back(')');

    return str;
}

////////////////////////////////////////////////////////////////////////////////////////
//                                   Token Semicolon                                  //
////////////////////////////////////////////////////////////////////////////////////////

TokenSemicolon::TokenSemicolon() : IToken(TokenType::Semicolon) {}

std::string TokenSemicolon::to_string() {
    auto str = std::string();

    str.append("Semicolon [;]");

    return str;
}