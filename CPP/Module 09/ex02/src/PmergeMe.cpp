#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& input): _c_vec(input)
{
	for (std::vector<int>::const_iterator	it = input.begin(); it != input.end(); ++it)
	{
		_c_deq.push_back(*it);		// add the element at the end
		_c_lst.push_back(*it);
	}
}

PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }

PmergeMe&	PmergeMe::operator = (const PmergeMe& src)
{
	if (this != &src)
	{
		this->_c_vec = src._c_vec;
		this->_c_deq = src._c_deq;
		this->_c_lst = src._c_lst;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

bool	PmergeMe::isPositiveNum(std::string av)
{
	std::string::iterator	it;

	for (it = av.begin(); it != av.end(); ++it)
		if (!isdigit(*it))
			return false;
	return true;
}

template <typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& src)
{
	for (typename std::vector<T>::const_iterator	it = src.begin(); it != src.end(); ++it)
		o << " " << *it;
	return o;
}

// Jacobsthal sequence: just like the Fibonacci sequence but slightly different
// 	J(0) = 0
// 	J(1) = 1
// 	J(n) = J(n-1) + 2 * J(n-2) for n > 1
std::vector<size_t>	generateJacobSeq(size_t n)
{
	std::vector<size_t>	JacobSeq;

	if (n == 0)
		return JacobSeq;
	JacobSeq.push_back(0);
	if (n == 1)
		return JacobSeq;
	JacobSeq.push_back(1);
	size_t	i = 2;
	while (JacobSeq.back() <= n)		// .back() returns a reference to the last element
	{
		size_t	next = JacobSeq[i - 1] + 2 * JacobSeq[i - 2];
		if (next > n)
			break ;
		JacobSeq.push_back(next);
		++i;
	}
	return JacobSeq;
}

std::vector<size_t>	getInsertionIndices(size_t n)
{
	std::vector<size_t>	JacobSeq = generateJacobSeq(n);
	
}

template <typename Iter, typename T>
Iter	binarySearch(Iter first, Iter last, const T& value, size_t* compares)
{

}

template <template <typename, typename> class Container, typename T, typename Alloc>
size_t	merge_insertion_sort(Container<T, Alloc>& cont,
	typename Container<T, Alloc>::iterator first, typename Container<T, Alloc>::iterator last)
{
	
}