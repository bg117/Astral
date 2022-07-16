#pragma once

#include <memory>

#include "token.hpp"

namespace Astral
{
    class ASTNode
    {
    };

    class ExprASTNode : ASTNode
    {
    };

    class StmtASTNode : ASTNode
    {
    };

    class UnaryExprASTNode final : ExprASTNode
    {
    public:
        UnaryExprASTNode(std::unique_ptr<ExprASTNode> expr, struct Token op);

        const std::unique_ptr<ExprASTNode> &expr() const;
        Token                               op() const;

    private:
        std::unique_ptr<ExprASTNode> m_expr;
        Token                        m_op;
    };

    class BinaryExprASTNode final : ExprASTNode
    {
    public:
        BinaryExprASTNode(std::unique_ptr<ExprASTNode> lhs,
                          std::unique_ptr<ExprASTNode> rhs,
                          struct Token                 op);

        const std::unique_ptr<ExprASTNode> &lhs() const;
        const std::unique_ptr<ExprASTNode> &rhs() const;
        Token                               op() const;

    private:
        std::unique_ptr<ExprASTNode> m_lhs;
        std::unique_ptr<ExprASTNode> m_rhs;
        Token                        m_op;
    };

    class NumberExprASTNode final : ExprASTNode
    {
    public:
        NumberExprASTNode(unsigned long long value);

        unsigned long long value() const;

    private:
        unsigned long long m_value;
    };
} // namespace Astral
