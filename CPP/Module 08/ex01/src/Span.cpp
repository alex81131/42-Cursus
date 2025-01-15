#include "Span.hpp"

Span::Span(void): _n(100), _stored(0)
{
	// std::cout << "[Span] Default constructor called." << std::endl;
}

Span::Span(unsigned int n): _n(n), _stored(0)
{
	// std::cout << "[Span] Parameterized constructor called." << std::endl;
}

Span::Span(const Span& src)
{
	// std::cout << "[Span] Copy constructor called." << std::endl;
	*this = src;
}

Span&	Span::operator = (const Span& src)
{
	// std::cout << "[Span] Assignment constructor called." << std::endl;
	if (this != &src)
	{
		this->_n = src._n;
		this->_stored = src._stored;
		this->_cont = src._cont;
	}
	return *this;
}

Span::~Span(void)
{
	// std::cout << "[SPAN] Destructor called." << std::endl;
}

void	Span::addNumber(int nb)
{
	if (_stored >= _n)
		throw  OutOfRangeException();
	std::vector<int>::iterator	it;

	for (it = _cont.begin(); it != _cont.end(); ++it)
		if (nb < *it)
			break;
	if (it == _cont.end())
		_cont.push_back(nb);
	else
		_cont.insert(it, 1, nb);
	_stored += 1;
}
// _cont.insert(pos, times, value):
// 	pos: position in the vector container
// 	times: number of times of the insertion
// 	value: value to be inserted

unsigned int	Span::shortestSpan(void) const
{
	if (_stored < 2)
		throw NoRangeException();
	unsigned int	range = *(_cont.begin() + 1) - *(_cont.begin());
	if (!range)
		return range;

	std::vector<int>::const_iterator	it;
	for (it = _cont.begin() + 1; it + 1 != _cont.end(); ++it)
	{
		unsigned int	temp = *(it + 1) - *it;
		if (temp < range)
			range = temp;
		if (range == 0)
			return range;
	}
	return range;
}

unsigned int	Span::longestSpan(void) const
{
	if (_stored < 2)
		throw NoRangeException();
	return (_cont.back() - _cont.front());
}
// .front():
// 	first element in the container
// .back():
// 	last element in the container

void	Span::printAll(void) const
{
	std::vector<int>::const_iterator	it;

	for (it = _cont.begin(); it !=_cont.end(); ++it)
		std:: cout << *it << std::endl;
}

void	Span::storeNumbers(unsigned int n)
{
	if (n > (_n - _stored))
		throw OutOfRangeException();
	srand(time(NULL));
	for (unsigned int i = 0; i < n; i++)
	{
		const int nb = rand();
		addNumber(nb);
	}
}

const char*	Span::OutOfRangeException::what() const throw()
{
	return "[Exception] Container full.";
}

const char*	Span::NoRangeException::what() const throw()
{
	return "[Exception] No span available.";
}
