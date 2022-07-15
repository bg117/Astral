cmake_minimum_required(VERSION 3.0)

add_executable(astral
    main.c

    lexer.c
    token.c
    parser.c

    lexer.h
    token.h
    parser.h
)
