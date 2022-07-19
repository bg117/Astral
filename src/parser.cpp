#include <memory>
#include <stdexcept>
#include <vector>

#include "token.hpp"

#include "ast.hpp"
#include "ast_visitor.hpp"
#include "lexer.hpp"
#include "parser.hpp"

Astral::Parser::Parser(std::vector<Token> tokens)
    : m_tokens(std::move(tokens)), m_it(m_tokens.begin())
{
}

std::unique_ptr<Astral::ASTNode> Astral::Parser::parse()
{
    return parse_expr();
}

std::unique_ptr<Astral::ExprASTNode> Astral::Parser::parse_expr()
{
    return parse_term_expr();
}

std::unique_ptr<Astral::ExprASTNode> Astral::Parser::parse_term_expr()
{
    auto lhs = parse_fact_expr();

    while (m_it->type == TokenType::Plus || m_it->type == TokenType::Minus)
    {
        auto token = *m_it;
        consume(m_it->type);
        lhs = std::make_unique<BinaryExprASTNode>(
            std::move(lhs), parse_fact_expr(), token);
    }

    return lhs;
}

std::unique_ptr<Astral::ExprASTNode> Astral::Parser::parse_fact_expr()
{
    auto lhs = parse_unary_expr();

    while (m_it->type == TokenType::Asterisk || m_it->type == TokenType::Slash)
    {
        auto token = *m_it;
        consume(m_it->type);
        lhs = std::make_unique<BinaryExprASTNode>(
            std::move(lhs), parse_unary_expr(), token);
    }

    return lhs;
}

std::unique_ptr<Astral::ExprASTNode> Astral::Parser::parse_unary_expr()
{
    if (m_it->type == TokenType::Minus)
    {
        auto token = *m_it;
        consume(TokenType::Minus);
        return std::make_unique<UnaryExprASTNode>(parse_unary_expr(), token);
    }

    return parse_primary_expr();
}

std::unique_ptr<Astral::ExprASTNode> Astral::Parser::parse_primary_expr()
{
    switch (m_it->type)
    {
    case TokenType::Number: return parse_number_expr();
    case TokenType::String: return parse_string_expr();
    case TokenType::LParen: return parse_grouped_expr();
    default:
        throw std::runtime_error{ std::string{ "unexpected token `" }
                                  + m_it->value + "` at line "
                                  + std::to_string(m_it->line) + ", column "
                                  + std::to_string(m_it->column) };
    }
}

std::unique_ptr<Astral::ExprASTNode> Astral::Parser::parse_grouped_expr()
{
    consume(TokenType::LParen);
    auto expr = parse_expr();
    consume(TokenType::RParen);

    return expr;
}

std::unique_ptr<Astral::ExprASTNode> Astral::Parser::parse_number_expr()
{
    auto token = *m_it;
    consume(TokenType::Number);
    return std::make_unique<NumberExprASTNode>(std::atoll(token.value.c_str()));
}

std::unique_ptr<Astral::ExprASTNode> Astral::Parser::parse_string_expr()
{
    auto token = *m_it;
    consume(TokenType::String);
    return std::make_unique<StringExprASTNode>(token.value);
}

void Astral::Parser::consume(TokenType type)
{
    if (is_at_end())
    {
        throw std::runtime_error{ std::string{
                                      "unexpected end of file at line " }
                                  + std::to_string(m_it->line) + ", column "
                                  + std::to_string(m_it->column) };
    }

    if (m_it->type != type)
    {
        throw std::runtime_error{ std::string{ "unexpected token `" }
                                  + m_it->value + "` at line "
                                  + std::to_string(m_it->line) + ", column "
                                  + std::to_string(m_it->column) };
    }

    ++m_it;
}

bool Astral::Parser::is_at_end()
{
    return m_it == m_tokens.cend();
}
