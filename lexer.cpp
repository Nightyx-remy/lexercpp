//
// Created by remy on 12/1/22.
//

#include "lexer.h"
#include <iostream>
#include <utility>

Lexer::Lexer(std::string src) {
    this->m_src = std::move(src);
    this->m_index = 0;
    if (this->m_index >= this->m_src.length()) {
        this->m_current = '\0'; // EOF
    } else {
        this->m_current = this->m_src[this->m_index];
    }
}

void Lexer::advance() {
    this->m_index += 1;
    if (this->m_index >= this->m_src.length()) {
        this->m_current = '\0'; // EOF
    } else {
        this->m_current = this->m_src[this->m_index];
    }
}

std::vector<std::shared_ptr<IToken>> Lexer::tokenize() {
    auto tokens = std::vector<std::shared_ptr<IToken>>();

    while (this->m_current != '\0') {
        if (isalpha(this->m_current)) {
            tokens.push_back(this->make_identifier());
        } else if (isdigit(this->m_current)) {
            tokens.push_back(this->make_number());
        } else {
            switch (this->m_current) {
                case '=':
                    tokens.push_back(std::make_shared<TokenEqual>());
                    break;
                case ';':
                    tokens.push_back(std::make_shared<TokenSemicolon>());
                    break;
                case '"':
                    tokens.push_back(this->make_string());
                    break;
                case ' ':
                case '\t':
                case '\n':
                case '\r':
                    // Ignored
                    break;
                default:
                    std::cout << "Unexpected char '" << this->m_current << "'!" << std::endl;
                    std::exit(1);
            }
            this->advance();
        }
    }

    return tokens;
}

std::shared_ptr<IToken> Lexer::make_identifier() {
    auto buf = std::string();

    while (isalnum(this->m_current) || this->m_current == '_') {
        buf.push_back(this->m_current);
        this->advance();
    }

    return std::make_shared<TokenIdentifier>(buf);
}

std::shared_ptr<IToken> Lexer::make_string() {
    auto buf = std::string();
    this->advance();

    while (this->m_current != '"') {
        if (this->m_current == '\0') {
            std::cout << "Unexpected char EOF!" << std::endl;
            std::exit(1);
        }
        buf.push_back(this->m_current);
        this->advance();
    }

    return std::make_shared<TokenString>(buf);
}

std::shared_ptr<IToken> Lexer::make_number() {
    auto buf = std::string();

    bool dot = false;

    while (isdigit(this->m_current) || this->m_current == '.') {
        if (this->m_current == '.') {
            if (dot) {
                std::cout << "Unexpected '.'!" << std::endl;
                std::exit(1);
            }
            dot = true;
        }
        buf.push_back(this->m_current);
        this->advance();
    }

    return std::make_shared<TokenNumber>(buf);
}
