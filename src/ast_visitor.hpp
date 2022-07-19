#pragma once

namespace Astral
{
    class ASTVisitor
    {
    public:
        virtual void visit(ASTNode &node) = 0;

        virtual void visit(ExprASTNode &node) = 0;
        virtual void visit(StmtASTNode &node) = 0;

        virtual void visit(UnaryExprASTNode &node)  = 0;
        virtual void visit(BinaryExprASTNode &node) = 0;
        virtual void visit(NumberExprASTNode &node) = 0;
        virtual void visit(StringExprASTNode &node) = 0;
    };
} // namespace Astral
