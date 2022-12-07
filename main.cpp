#include <iostream>
#include "lexer.h"

int main() {
    auto lexer = Lexer("var a = \"Hello, World\"; var b = 12.2;");

    auto tokens = lexer.tokenize();

    for (auto& token : tokens) {
        std::cout << token->to_string() << std::endl;
    }
    return 0;
}
