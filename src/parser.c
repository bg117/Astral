#include "parser.h"
#include "lexer.h"
#include "token.h"

void parser_init(parser_t *parser, lexer_t *lexer)
{
    token_t eof_token = token_init("", TOKEN_EOF, 0, 0);

    parser->lexer          = lexer;
    parser->previous_token = eof_token;
    parser->current_token  = lexer_next_token(lexer);
}
