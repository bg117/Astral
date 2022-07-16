#pragma once

#include <string>

namespace Astral
{
    enum class TokenType
    {
#define X(a, b) a,
#include "token.enum"
#undef X
    };

    struct Token
    {
        std::string value;
        TokenType   type;

        unsigned long line, column;

        static const char *type_to_string(TokenType type);
    };
} // namespace Astral
