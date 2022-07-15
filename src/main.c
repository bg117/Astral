#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "parser.h"
#include "token.h"

int main(int argc, char **argv)
{
    puts("Astral interpreter");

    if (argc < 2)
    {
        fputs("Please specify a file.", stderr);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp)
    {
        fprintf(stderr, "Cannot open file %s: %s\n", argv[1], strerror(errno));
        return 2;
    }

    fseek(fp, 0, SEEK_SET);
    long file_size = ftell(fp);

    char *file_buffer
        = calloc(file_size + 1 /* for NUL char */, sizeof *file_buffer);

    size_t read = fread(file_buffer, 1, file_size, fp);
    if (read != file_size)
    {
        fprintf(
            stderr, "Failed to read file %s: %s\n", argv[1], strerror(errno));
        return 3;
    }

    fclose(fp);

    lexer_t  lexer;
    parser_t parser;

    lexer_init(&lexer, file_buffer);
    parser_init(&parser, &lexer);

    return 0;
}
