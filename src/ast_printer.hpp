#pragma once

namespace Astral
{
    class ASTPrinter : public ASTVisitor
    {
    public:
        ASTPrinter(ASTNode &root);

        void print(std::ostream &os = std::cout);

        void visit(ASTNode &node) override;

        void visit(ExprASTNode &node) override;
        void visit(StmtASTNode &node) override;

        void visit(UnaryExprASTNode &node) override;
        void visit(BinaryExprASTNode &node) override;
        void visit(NumberExprASTNode &node) override;
        void visit(StringExprASTNode &node) override;

    private:
        ASTNode    &m_root;
        std::string m_result;
    };
} // namespace Astral
