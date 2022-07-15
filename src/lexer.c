#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"
#include "token.h"

void lexer_init(lexer_t *lexer, const char *src)
{
    lexer->src    = src;
    lexer->line   = 1;
    lexer->column = 1;
}

token_t lexer_next_token(lexer_t *lexer)
{
    token_t token = token_init("", TOKEN_EOF, 0, 0);
    return token;
}
