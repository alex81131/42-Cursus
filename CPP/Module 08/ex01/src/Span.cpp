#include "Span.hpp"

Span::Span(void): _maxSize(100)
{
	// std::cout << "[Span] Default constructor called." << std::endl;
}

Span::Span(unsigned int n): _maxSize(n)
{
	// std::cout << "[Span] Parameterized constructor called." << std::endl;
}

Span::Span(const Span& src)
{
	// std::cout << "[Span] Copy constructor called." << std::endl;
	*this = src;
}

Span&	Span::operator=(const Span& src)
{
	// std::cout << "[Span] Assignment constructor called." << std::endl;
	if (this != &src)
	{
		this->_maxSize = src._maxSize;
		this->_cont = src._cont;
	}
	return *this;
}

Span::~Span(void)
{
	// std::cout << "[SPAN] Destructor called." << std::endl;
}

void	Span::addNumber(int value)
{
	if (_cont.size() >= _maxSize)
		throw OutOfRangeException();

	std::vector<int>::iterator	it = std::lower_bound(_cont.begin(), _cont.end(), value);
	_cont.insert(it, value);
}
// std::lower_bound performs a binary search, making it faster (O(log n)) than a linear search.
// 	It returns an iterator to the first element that is not less than value.
// 	If all elements are smaller, it returns the end iterator,
// 	indicating that value should be inserted at the end.

// _cont.insert(pos, value):
// 	insert "value" at the "position".

void	Span::addNumber(int value, int n)
{
	if (_cont.size() + n > _maxSize)
		throw OutOfRangeException();

	std::vector<int>::iterator	it = std::lower_bound(_cont.begin(), _cont.end(), value);
	_cont.insert(it, n, value);
}
// _cont.insert(pos, times, value):
// 	pos: position in the vector container
// 	times: number of times of the insertion
// 	value: value to be inserted

// std::sort(A, B):
// 	sorts the elements between A and B in ascending order
unsigned int	Span::shortestSpan(void)
{
	if (_cont.size() < 2)
		throw NoRangeException();
	std::sort(_cont.begin(), _cont.end());
	unsigned int	min = std::numeric_limits<int>::max();

	for (std::vector<int>::const_iterator it = _cont.begin(); it + 1 != _cont.end(); it++)
	{
		unsigned int	range = *(it + 1) - *it;
		min = min < range ? min : range;
	}
	return min;
}

unsigned int	Span::longestSpan(void)
{
	if (_cont.size() < 2)
		throw NoRangeException();
	return *(std::max_element(_cont.begin(), _cont.end())) - *(std::min_element(_cont.begin(), _cont.end()));
}
// .front():
// 	first element in the container
// .back():
// 	last element in the container

void	Span::printAll(void) const
{
	std::vector<int>::const_iterator	it;

	for (it = _cont.begin(); it !=_cont.end(); ++it)
		std::cout << *it << std::endl;
}

void	Span::storeNumbers(unsigned int n)		// Store n random numbers
{
	if (n > (_maxSize - _cont.size()))
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
