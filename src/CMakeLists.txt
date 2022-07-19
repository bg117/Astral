cmake_minimum_required(VERSION 3.0)

add_executable(astral
    main.cpp

    lexer.cpp
    token.cpp
    parser.cpp
    ast.cpp
    ast_printer.cpp

    lexer.hpp
    token.hpp
    parser.hpp
    ast.hpp
    ast_visitor.hpp
    ast_printer.hpp
)
