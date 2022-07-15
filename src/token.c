#include "token.h"

token_t token_init(char         *value,
                   int           type,
                   unsigned long line,
                   unsigned long column)
{
    token_t token;
    token.value  = value;
    token.type   = type;
    token.line   = line;
    token.column = column;

    return token;
}
