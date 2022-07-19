#include <cctype>
#include <stdexcept>
#include <string>

#include "token.hpp"

#include "lexer.hpp"

Astral::Lexer::Lexer(std::string src)
    : m_src(std::move(src)), m_it(m_src.begin()), m_line(1), m_column(1)
{
}

void Astral::Lexer::reset()
{
    m_it     = m_src.begin();
    m_line   = 1;
    m_column = 1;
}

Astral::Token Astral::Lexer::next_token()
{
    Token token{ "", TokenType::Eof, m_line, m_column };

    skip_whitespace();

    if (is_at_end())
        return token;

    token.line   = m_line;
    token.column = m_column;

    switch (*m_it)
    {
    case '+':
        token.type  = TokenType::Plus;
        token.value = "+";
        break;
    case '-':
        token.type  = TokenType::Minus;
        token.value = "-";
        break;
    case '*':
        token.type  = TokenType::Asterisk;
        token.value = "*";
        break;
    case '/':
        token.type  = TokenType::Slash;
        token.value = "/";
        break;
    case '"':
    case '\'': return collect_string();
    default:
        if (std::isdigit(*m_it))
            return collect_number();

        throw std::runtime_error{ std::string{ "unknown token `" } + *m_it
                                  + "` at line " + std::to_string(m_line)
                                  + ", column " + std::to_string(m_column) };
    }

    advance();

    return token;
}

bool Astral::Lexer::is_at_end()
{
    return m_it == m_src.cend();
}

void Astral::Lexer::advance()
{
    if (is_at_end())
        return;

    m_column++;
    if (*m_it == '\n')
    {
        m_line++;
        m_column = 0;
    }

    m_it++;
}

void Astral::Lexer::skip_whitespace()
{
    while (!is_at_end()
           && (*m_it == ' ' || *m_it == '\r' || *m_it == '\n' || *m_it == '\t'
               || *m_it == '\f' || *m_it == '\v'))
    {
        advance();
    }
}

Astral::Token Astral::Lexer::collect_string()
{
    char quote = *m_it;
    advance();

    Astral::Token token{ .type   = TokenType::String,
                         .line   = m_line,
                         .column = m_column };
    std::string   buf{};

    while (!is_at_end() && *m_it != '"')
    {
        buf += *m_it;
        advance();
    }

    if (is_at_end())
    {
        throw std::runtime_error{ std::string{ "unexpected end of file" }
                                  + " at line " + std::to_string(m_line)
                                  + ", column " + std::to_string(m_column) };
    }

    if (*m_it != quote)
    {
        throw std::runtime_error{ std::string{ "mismatched closing quote" }
                                  + " at line " + std::to_string(m_line)
                                  + ", column " + std::to_string(m_column) };
    }

    token.value = buf;

    advance();
    return token;
}

Astral::Token Astral::Lexer::collect_number()
{
    Astral::Token token{ .type   = TokenType::Number,
                         .line   = m_line,
                         .column = m_column };
    std::string   buf{};

    while (!is_at_end() && std::isdigit(*m_it))
    {
        buf += *m_it;
        advance();
    }

    token.value = buf;
    return token;
}
