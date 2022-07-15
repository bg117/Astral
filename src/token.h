#pragma once

enum TOKEN_TYPE
{
    TOKEN_EOF,
    TOKEN_UNKNOWN,

    TOKEN_STRING_LITERAL,
    TOKEN_NUMERIC_LITERAL,
    TOKEN_CHAR_LITERAL,

    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_ASTERISK,
    TOKEN_SLASH
};

typedef struct _token
{
    char *value;
    int   type;

    unsigned long line, column;
} token_t;

token_t token_init(char         *value,
                   int           type,
                   unsigned long line,
                   unsigned long column);
