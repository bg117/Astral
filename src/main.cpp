#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "lexer.hpp"
#include "parser.hpp"
#include "token.hpp"

int main(int argc, char **argv)
{
    std::cout << "Astral interpreter" << std::endl;

    if (argc < 2)
    {
        std::cerr << "Please specify a file" << std::endl;
        return 1;
    }

    std::ifstream ifs{ argv[1] };
    std::string   file_buffer{ std::istreambuf_iterator<char>{ ifs },
                             std::istreambuf_iterator<char>{} };

    ifs >> file_buffer;

    Astral::Lexer  lexer{ file_buffer };
    Astral::Parser parser{};
    Astral::Token  token{};

    std::vector<Astral::Token> token_list{};

    while (true)
    {
        token = lexer.next_token();

        if (token.type == Astral::TokenType::Eof)
            break;

        token_list.emplace_back(token);
    }

    for (const auto &x : token_list)
    {
        std::cout << "token { value=\"" << x.value
                  << "\"; type=" << Astral::Token::type_to_string(x.type)
                  << "; line=" << x.line << "; column=" << x.column << "; }"
                  << std::endl;
    }

    return 0;
}
