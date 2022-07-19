#pragma once

namespace Astral
{
    class ASTVisitor;

    class ASTNode
    {
    public:
        virtual void accept(ASTVisitor &visitor) = 0;
    };

    class ExprASTNode : public ASTNode
    {
    };

    class StmtASTNode : public ASTNode
    {
    };

    class UnaryExprASTNode final : public ExprASTNode
    {
    public:
        UnaryExprASTNode(std::unique_ptr<ExprASTNode> expr, Token op);

        const std::unique_ptr<ExprASTNode> &expr() const;
        Token                               op() const;

        void accept(ASTVisitor &visitor) override;

    private:
        std::unique_ptr<ExprASTNode> m_expr;
        Token                        m_op;
    };

    class BinaryExprASTNode final : public ExprASTNode
    {
    public:
        BinaryExprASTNode(std::unique_ptr<ExprASTNode> lhs,
                          std::unique_ptr<ExprASTNode> rhs,
                          Token                        op);

        const std::unique_ptr<ExprASTNode> &lhs() const;
        const std::unique_ptr<ExprASTNode> &rhs() const;
        Token                               op() const;

        void accept(ASTVisitor &visitor) override;

    private:
        std::unique_ptr<ExprASTNode> m_lhs;
        std::unique_ptr<ExprASTNode> m_rhs;
        Token                        m_op;
    };

    class NumberExprASTNode final : public ExprASTNode
    {
    public:
        NumberExprASTNode(unsigned long long value);

        unsigned long long value() const;

        void accept(ASTVisitor &visitor) override;

    private:
        unsigned long long m_value;
    };

    class StringExprASTNode final : public ExprASTNode
    {
    public:
        StringExprASTNode(std::string value);

        std::string value() const;

        void accept(ASTVisitor &visitor) override;

    private:
        std::string m_value;
    };
} // namespace Astral
