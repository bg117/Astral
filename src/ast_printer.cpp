#include <iostream>
#include <memory>

#include "token.hpp"

#include "ast.hpp"

#include "ast_visitor.hpp"

#include "ast_printer.hpp"

Astral::ASTPrinter::ASTPrinter(ASTNode &root) : m_root(root)
{
}

void Astral::ASTPrinter::print(std::ostream &os)
{
    m_root.accept(*this);
    os << m_result << std::endl;
}

void Astral::ASTPrinter::visit(ASTNode &node)
{
    node.accept(*this);
}

void Astral::ASTPrinter::visit(ExprASTNode &node)
{
    node.accept(*this);
}

void Astral::ASTPrinter::visit(StmtASTNode &node)
{
    node.accept(*this);
}

void Astral::ASTPrinter::visit(UnaryExprASTNode &node)
{
    m_result += '(';
    m_result += node.op().value;
    node.expr()->accept(*this);
    m_result += ')';
}

void Astral::ASTPrinter::visit(BinaryExprASTNode &node)
{
    m_result += '(';
    node.lhs()->accept(*this);
    m_result += node.op().value;
    node.rhs()->accept(*this);
    m_result += ')';
}

void Astral::ASTPrinter::visit(NumberExprASTNode &node)
{
    m_result += std::to_string(node.value());
}

void Astral::ASTPrinter::visit(StringExprASTNode &node)
{
    m_result += '"' + node.value() + '"';
}
