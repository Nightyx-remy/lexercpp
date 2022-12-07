//
// Created by remy on 12/1/22.
//

#ifndef LEXERCPP_LEXER_H
#define LEXERCPP_LEXER_H

#include <string>
#include <vector>
#include <memory>
#include "tokens.h"

class Lexer {
private:
    std::string m_src;
    uintptr_t m_index;
    char m_current;

    void advance();

    std::shared_ptr<IToken> make_identifier();
    std::shared_ptr<IToken> make_string();
    std::shared_ptr<IToken> make_number();
public:
    Lexer(std::string src);

    std::vector<std::shared_ptr<IToken>> tokenize();
};


#endif //LEXERCPP_LEXER_H
