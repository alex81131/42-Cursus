#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN& src): _stack(src._stack) {}

RPN&	RPN::operator = (const RPN& src)
{
	// std::cout << "[RPN] Assignment constructor called." << std::endl;
	if (this != &src)
		_stack = src._stack;
	return *this;
}

RPN::~RPN(void) {}

double	RPN::calculation(const std::string& str)
{
	std::istringstream	iss(str);
	std::string			token;

	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
			do_operator(token);
		else
			do_number(token);
	}
	// Check only 2 numbers before an operator,
	// 	rendering the _stack.size() == 1.
	if (_stack.size() != 1)
		throw std::logic_error("Error: Invalid input.");
	return _stack.top();
}
// The >> operator when used with input streams (like iss) performs formatted input.
// 	It extracts a token from the stream.  By default, the >> operator uses whitespace (spaces, tabs, newlines)
// 	as delimiters to separate tokens.
// str = "3 4 +":
// 1. The first time iss >> token is executed, it reads "3" (up to the first space) and stores it in the token variable.
// 	→ do_number(3);
// 	→ 3 stored in _stack.
// 2. The second time,  it reads "4" (up to the next space) and stores it in token.
// 	→ do_number(4);
// 	→ 4 stored in _stack.
// 3. The third time, it reads "+" and stores it in token.
// 	→ do_operator(+);
// 	→ _stack.top(), the 1st element of the stack, is 4. Thus, "right" instead of "left".
// 	(token is not _stack)

// std::logic_error: 是在程式執行前能夠檢查出來的錯誤，通常代表程式邏輯本身的錯誤。
// std::runtime_error: 是在程式執行期間發生的錯誤，無法在編譯時預知的錯誤。
// 當檢查到用戶輸入不正確（如日期格式錯誤或非法數字）時，使用 std::logic_error 更合適。

void	RPN::do_operator(const std::string& token)
{
	if (_stack.size() < 2)
		throw std::logic_error("Error: Invalid format => " + token);
	double	right = _stack.top(); _stack.pop();		// .top(): get the top element
	double	left = _stack.top(); _stack.pop();		// .pop(): remove the top element

	if (token == "+")
		_stack.push(left + right);
	else if (token == "-")
		_stack.push(left - right);
	else if (token == "*")
		_stack.push(left * right);
	else if (token == "/")
	{
		if (right == 0)
			throw std::logic_error("Error: Division by zero.");
		_stack.push(left / right);
	}
}

void	RPN::do_number(const std::string& token)
{
	std::istringstream	iss(token);
	double				i;

	if (iss >> i)
	{
		// Removing this if makes this program capable of taking any number (that can be formatted in double)
		if (i < 0 || i > 9)
			throw std::logic_error("Error: Input out of range (0~9) => " + token);
		_stack.push(i);
	}
	else
		throw std::logic_error("Error: Invalid input => " + token);
}
