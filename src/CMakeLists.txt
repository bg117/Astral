cmake_minimum_required(VERSION 3.0)

add_executable(astral
    main.cpp

    lexer.cpp
    token.cpp
    parser.cpp

    lexer.hpp
    token.hpp
    parser.hpp
)
