#pragma once

# include <iostream>	// cout
# include <iomanip>		//  std::fixed, std::setprecision
# include <string>		// argv iterator

// We use these 3 containers to compare the performances of
// 	 the same merge-insertion sort algorithm across various data structure.
# include <vector>		// Excellent for random access (accessing elements by index), but insertions/deletions in the middle can be slow.
# include <deque>		// Good for insertions/deletions at both ends, and provides reasonable random access.
# include <list>		// Very efficient for insertions/deletions anywhere in the list, but random access is slow.

# include <algorithm>	// std::sort, std::min, std::max, std::lower_bound, std::copy...
# include <ctime>		// clock()
# include <exception>

class	PmergeMe
{
	public:
		PmergeMe();										// Default constructor
		PmergeMe(const std::vector<int>& input);		// Parameterized Constructor
		PmergeMe(const PmergeMe& src);					// Copy constructor
		PmergeMe&	operator = (const PmergeMe& src);	// Assignment operator
		~PmergeMe();									// Destructor

		static bool	isPositiveNum(std::string av);

	private:
		std::vector<int>	_c_vec;
		std::deque<int>		_c_deq;
		std::list<int>		_c_lst;
};

template <typename T>
std::ostream& operator << (std::ostream& o, const std::vector<T>& src);

std::vector<size_t>	generateJacobSeq(size_t n);		// Create a sequence of insertion indices (where to insert)
std::vector<size_t>	getInsertionIndices(size_t n);	// Use the Jacobsthal numbers (sequence above) to calculate the optimal order of insertions.

template <typename Iter, typename T>
Iter	binarySearch(Iter first, Iter last, const T& value, size_t* compares);

template <template <typename, typename> class Container, typename T, typename Alloc>
size_t	merge_insertion_sort(Container<T, Alloc>& cont,
	typename Container<T, Alloc>::iterator first, typename Container<T, Alloc>::iterator last);
// template <typename, typename> class Container:
// 	means that Container itself is a template that takes two type arguments,
// 	allowing the merge_insertion_sort function to work with different container types.
// T:
// 	the type of the elements stored in the container.
// Alloc:
// 	the allocator type of the container, for memory management.