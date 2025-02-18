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

// The n below is the number to define the size of the Jacobsthal sequence,
// 	 not the n-th element. Hence, the size of the sequence is not n.
// ie. The sequence: {1, 3, 5, 11, ...}
// 	with n = 10, the function gives  {1, 3, 5}.
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

std::vector<size_t>	getInsertionindex(size_t n)
{
	std::vector<size_t>	JacobSeq = generateJacobSeq(n);
	std::vector<size_t>	index;

	if (n == 0)
		return index;
	index.push_back(1);
	if (n == 1)
		return index;
	for (size_t i = 1; i < JacobSeq.size(); i++)
	{
		if (index.back() < JacobSeq[i])
		{
			size_t	tmp = JacobSeq[i - 1];
			index.push_back(JacobSeq[i]);
			for (size_t j = JacobSeq[i] - 1; j > tmp; j--)
				index.push_back(j);
		}
	}
	for (size_t k = n; k > JacobSeq.back(); k--)
		index.push_back(k);
	return index;
}
// Take n = 10 for example. JacobSeq = {1, 3, 5}.
// 1. Iteration 1 (i = 1, JacobSeq[1] = 3)
// 	- index.back() = 1
// 	- Since 1 < 3, we:
// 		- Push 3: {1, 3}
// 		- Fill the gap from 3-1 = 2 to tmp = 1 (numbers between 1~3) → Push 2: {1, 3, 2}.
// 2. Iteration 2 (i = 2, JacobSeq[2] = 5)
// 	- index.back() = 2
// 	- Since 2 < 5, we:
// 		- Push 5: {1, 3, 2, 5, 4}
// 		- Fill the gap from 5-1 = 4 to tmp = 3 → Push 4: {1, 3, 2, 5, 4}.
// 3. Handling remaining numbers (n = 10)
// 	- Push 10, 9, 8, 7, 6: {1, 3, 2, 5, 4, 10, 9, 8, 7, 6}
// Plus: Why descending order?
// 	1. The largest gaps are filled first.
// 	2. The binary search space is reduced early on.
// 	3. Comparisons remain minimal, improving efficiency.
// 	Advantage:
// 		This ensures that each number is inserted into a more structured array,
// 		reducing the overall number of comparisons.

// binarySearch(first element in the group, last element, value to look for, number of comparison)
template <typename Iter, typename T>
Iter	binarySearch(Iter first, Iter last, const T& value, size_t* compare_nb)
{
	Iter	it;
	typename std::iterator_traits<Iter>::difference_type	range, mid;
	range = std::distance(first, last);

	while (range > 0)
	{
		it = first;
		mid = range / 2;
		std::advance(it, mid);		// Put the iterator at the half point

		*compare_nb += 1;
		if (*it < value)			// If the middle < value, the value is on the right half
		{
			first = ++it;			// Ignoring the left half, ++it is now the first element on the right half
			range -= mid + 1;		// Remove the old middle
		}
		else
			range = mid;
	}
	return first;
}
// std::iterator_traits<Iter>:
// 	A trait class that extracts information about an iterator 
// difference_type:
// 	The type used to measure distances between iterators.

template <template <typename, typename> class Container, typename T, typename Alloc>
size_t	merge_insertion_sort(Container<T, Alloc>& cont,
	typename Container<T, Alloc>::iterator first,
	typename Container<T, Alloc>::iterator last)
{
	typedef typename Container<T, Alloc>::iterator					cont_it;
	typedef typename Alloc::template rebind<std::pair<T, T>::other	PairAlloc;
	typedef typename Conatiner<std::pair<T, T>, PairAlloc>::iterator	pair_it;
	(void)cont;
	size_t	compare_nb= = 0;

	dize_t	diff = std::distance(first, last);
	if (diff <= 1)
		return compare_nb;

	/* * * * Step 1: Create n/2 pairs * * * */
	Container<std::pair<T, T>, PairAlloc>	pairs;
	Container<T, Alloc>						remaining;

	cont_it = first;
	while (std::distance(it, last) > 1)
	{
		T	val_first = *(it++);
		T	val_second = *(it++);
		compare_nb++;
		if (val_second < val_first)
			std::swap(val_first, val_second);
		pairs.push_back(std::make_pair(val_first, val_second));
	}
	if (it != last)
		remaining.push_back(*it);

	/* * * * Step 2: Sort the pairs by the larger number * * * */
	Container<T, Alloc>	mainGroup;

	for (pair_it	itp = pairs.begin(); itp != pairs.end(); ++itp)
		mainGroup.push_back(itp->second);
	if (mainGroup.size() > 1)		// Sort recursively
		compare_nb += merge_insertion_sort(mainGroup, mainGroup.begin(), mainGroup.end())

	/* * * * Step 3: Sort the pairs by the larger number * * * */

	/* * * * Step 4: Sort the pairs by the larger number * * * */
	std::vector<size_t>	index = getInsertionindex()
}