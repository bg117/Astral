#pragma once

#include "token.h"
typedef struct _lexer lexer_t;

typedef struct _parser
{
    lexer_t *lexer;
    token_t  previous_token;
    token_t  current_token;
} parser_t;

void parser_init(parser_t *parser, lexer_t *lexer);
