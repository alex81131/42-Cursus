#pragma once
# include "json.hpp"
# include "lexer.hpp"
# include <fstream>
# include <iostream>
# include <stdexcept>

class	JsonParser
{
	public:
		static JsonValue	parse(std::ifstream& stream);

	private:
		typedef std::pair<std::string, JsonValue*>	Member;

		typedef JsonLexer::Tokens::iterator			iter;
		typedef JsonLexer::Tokens::const_iterator	const_iter;

		static JsonValue				handle_tokens(const_iter& begin, const const_iter& end);
		static JsonValue				handle_object(const_iter& begin, const const_iter& end);
		static JsonValue				handle_array(const_iter& begin, const const_iter& end);
		static JsonValue::member_type	handle_member(const_iter& begin, const const_iter& end);
};