#pragma once

#include <memory>
namespace Astral
{
    class Parser
    {
    public:
        Parser(std::vector<Token> tokens);

        std::unique_ptr<ASTNode> parse();

    private:
        std::vector<Token>           m_tokens;
        std::vector<Token>::iterator m_it;

        void consume(TokenType type);

        bool is_at_end(void);

        std::unique_ptr<ExprASTNode> parse_expr();
        std::unique_ptr<ExprASTNode> parse_term_expr();
        std::unique_ptr<ExprASTNode> parse_fact_expr();
        std::unique_ptr<ExprASTNode> parse_unary_expr();
        std::unique_ptr<ExprASTNode> parse_primary_expr();
        std::unique_ptr<ExprASTNode> parse_grouped_expr();
        std::unique_ptr<ExprASTNode> parse_number_expr();
        std::unique_ptr<ExprASTNode> parse_string_expr();
    };
} // namespace Astral
