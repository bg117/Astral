#include "ast.hpp"

Astral::UnaryExprASTNode::UnaryExprASTNode(
    std::unique_ptr<Astral::ExprASTNode> expr, Astral::Token op)
    : m_expr(std::move(expr)), m_op(op)
{
}

const std::unique_ptr<Astral::ExprASTNode> &Astral::UnaryExprASTNode::expr()
    const
{
    return m_expr;
}

Astral::Token Astral::UnaryExprASTNode::op() const
{
    return m_op;
}

Astral::BinaryExprASTNode::BinaryExprASTNode(
    std::unique_ptr<Astral::ExprASTNode> lhs,
    std::unique_ptr<Astral::ExprASTNode> rhs,
    Astral::Token                        op)
    : m_lhs(std::move(lhs)), m_rhs(std::move(rhs)), m_op(op)
{
}

const std::unique_ptr<Astral::ExprASTNode> &Astral::BinaryExprASTNode::lhs()
    const
{
    return m_lhs;
}

const std::unique_ptr<Astral::ExprASTNode> &Astral::BinaryExprASTNode::rhs()
    const
{
    return m_rhs;
}

Astral::Token Astral::BinaryExprASTNode::op() const
{
    return m_op;
}

Astral::NumberExprASTNode::NumberExprASTNode(unsigned long long value)
    : m_value(value)
{
}

unsigned long long Astral::NumberExprASTNode::value() const
{
    return m_value;
}
