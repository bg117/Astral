#pragma once

namespace Astral
{
    class Lexer
    {
    public:
        Lexer(std::string src);

        Token next_token();
        void  reset();

    private:
        std::string           m_src;
        std::string::iterator m_it;

        unsigned long m_line, m_column;

        bool is_at_end();

        void advance();

        void skip_whitespace();

        Token collect_string();
        Token collect_number();
    };
} // namespace Astral
