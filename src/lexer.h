#pragma once

typedef struct _token token_t;

typedef struct _lexer
{
    const char   *src;
    unsigned long line, column;
} lexer_t;

void    lexer_init(lexer_t *lexer, const char *src);
token_t lexer_next_token(lexer_t *lexer);
