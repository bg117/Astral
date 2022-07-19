#include "token.hpp"

static const char *type_strings[] = {
#define X(a, b) #b,
#include "token.enum"
#undef X
};

const char *Astral::Token::type_to_string(TokenType type)
{
    return type_strings[(int)type];
}
