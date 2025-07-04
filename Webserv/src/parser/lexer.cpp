#include "lexer.hpp"

static const std::string	whitespace = "\t\r\n ";
static const std::string	all_chars = "{}[];,\"" + whitespace;
JsonLexer::Tokens			JsonLexer::_tokens;

struct	Keywords
{
	enum	Value
	{
		KTRUE,
		KFALSE,
		KNULL
	};
};

std::map<Keywords::Value, std::string>	init_keywords()
{
	std::map<Keywords::Value, std::string>	map;

	map.insert(std::make_pair(Keywords::KTRUE, "true"));
	map.insert(std::make_pair(Keywords::KFALSE, "false"));
	map.insert(std::make_pair(Keywords::KNULL, "null"));
	return map;
}

static const std::map<Keywords::Value, std::string> keywords = init_keywords();

void	JsonLexer::loop(iter begin, iter end)
{
	for (; begin < end; begin++)
	{
		switch (*begin)
		{
			case '{': _tokens.push_back(Token(TokenType::LCURLY)); break;
			case '}': _tokens.push_back(Token(TokenType::RCURLY)); break;
			case '[': _tokens.push_back(Token(TokenType::LBRAC)); break;
			case ']': _tokens.push_back(Token(TokenType::RBRAC)); break;
			case ',': _tokens.push_back(Token(TokenType::COMMA)); break;
			case ':': _tokens.push_back(Token(TokenType::COLON)); break;
			case '"': _tokens.push_back(handle_string(begin, end)); break;
			case '\t': case '\r': case '\n': case ' ': break;
			default:
				_tokens.push_back(handle_complete(begin, end));
				begin--;
				break;
		}
	}
}

JsonLexer::Tokens	JsonLexer::lex(std::ifstream& stream)
{
	std::string	_data;
	std::string	_buf;
	size_t		line_counter = 1;

	while (std::getline(stream, _buf))
	{
		if (_buf.erase(0, _buf.find_first_not_of(" \n\r\t")).find("//") == 0)
			continue;
		try
		{
			loop(_buf.begin(), _buf.end());
		}
		catch (const std::exception& e)
		{
			std::cerr << "line ["<< line_counter << "]: caught [" << e.what() << "]: " << std::endl;
		}
		_data += "line: " + _buf + "\n";
		line_counter++;
	}
	// std::cout << _data << std::endl;
	// debug();
	return _tokens;
}

JsonLexer::Token	JsonLexer::handle_string(std::string::iterator& begin, const std::string::iterator& end)
{
	std::string s;
	if (std::find(begin++, end, '"') == end)
		throw std::runtime_error("Syntax Error: No closing quote [handle_string()].\n");
	while (begin < end)
	{
		if (*begin == '"')
			break;
		s.push_back(*begin);
		begin++;
	}
	return Token(JsonLexer::TokenType::STRING, s);
}

JsonLexer::Token	JsonLexer::handle_complete(iter& begin, const iter& end)
{
	Token					token;
	std::string::iterator	end_word = std::find_first_of(begin, end, all_chars.begin(), all_chars.end());
	std::string				word;

	for (; begin < end_word; ++begin)
		word.push_back(*begin);

	if (word == "true")
		token.type = JsonLexer::TokenType::VTRUE;
	else if (word == "false")
		token.type = JsonLexer::TokenType::VFALSE;
	else if (word == "null")
		token.type = JsonLexer::TokenType::VNULL;
	else if (!word.empty() && word.find_first_not_of("0123456789.-") == std::string::npos
			&& std::count(word.begin(), word.end(), '-') < 2
			&& std::count(word.begin(), word.end(), '.') < 2
			&& *word.begin() != '.' && *--word.end() != '.')
	{
		token.type = JsonLexer::TokenType::DECIMAL;
		token.value = word;
	}
	else
		throw std::runtime_error("Syntax Error: Invalid 'word' token [handle_complete()].\n");
	return token;
}

void	JsonLexer::debug()
{
	std::cout << "Tokens:\n";
	std::vector<Token>::const_iterator	it;

	for (it = _tokens.begin(); it < _tokens.end(); it++)
	{
		Token	token = *it;
		std::cout << "[" << token.type << "] " << token_type_to_string(token.type);
		if (token.type == TokenType::STRING)
			std::cout << "(\"" << token.value << "\")";
		else if (token.type == TokenType::DECIMAL)
			std::cout << "(" << token.value << ")";
		std::cout << "\n";
	}
}

std::string	JsonLexer::token_type_to_string(JsonLexer::TokenType::Value type)
{
	switch (type)
	{
		case TokenType::LCURLY: return "LCURLY";
		case TokenType::RCURLY: return "RCURLY";
		case TokenType::LBRAC: return "LBRAC";
		case TokenType::RBRAC: return "RBRAC";
		case TokenType::COMMA: return "COMMA";
		case TokenType::COLON: return "COLON";
		case TokenType::VTRUE: return "TRUE";
		case TokenType::VFALSE: return "FALSE";
		case TokenType::VNULL: return "NULL";
		case TokenType::STRING: return "STRING";
		case TokenType::DECIMAL: return "DECIMAL";
		default: return "UNKNOWN";
	}
}