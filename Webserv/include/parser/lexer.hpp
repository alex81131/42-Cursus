#pragma once
# include <vector>
# include <string>
# include <algorithm>
# include <cstddef>
# include <iostream>
# include <map>
# include <stdexcept>
# include <fstream>

class	JsonLexer
{
	public:
		struct	TokenType
		{
			enum	Value
			{
				LCURLY,
				RCURLY,
				LBRAC,
				RBRAC,
				COMMA,
				COLON,
				VTRUE,
				VFALSE,
				VNULL,
				STRING,
				DECIMAL,
			};
		};

		struct	Token
		{
			TokenType::Value	type;
			std::string			value;

			Token() {}
			Token(TokenType::Value _val): type(_val) {}
			Token(TokenType::Value _val, std::string _str): type(_val), value(_str) {}
		};

		typedef std::string::iterator		iter;
		typedef std::string::const_iterator	const_iter;
		typedef std::vector<Token>			Tokens;

		static Tokens						lex(std::ifstream& stream);
		static void							debug();

	private:
		static Tokens		_tokens;
		static void			loop(iter begin, iter end);

		static Token		handle_string(iter& begin, const iter& end);
		static Token		handle_complete(iter& begin, const iter& end);
		static std::string	token_type_to_string(JsonLexer::TokenType::Value type);
};