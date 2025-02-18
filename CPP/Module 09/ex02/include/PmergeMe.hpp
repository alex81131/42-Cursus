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

// Merge-Insertion Sort:
// Let us say we are sorting the numbers {8, 3, 10, 1, 5, 4, 7, 6, 2, 9}.
// The process follows these steps:
// 1. Pair elements → {(8,3), (10,1), (5,4), (7,6), (2,9)}
// 	- Take the larger of each pair as the initial sorted list: {8, 10, 5, 7, 9}
// 	- The smaller elements ({3, 1, 4, 6, 2}) are "pending" insertions.
// 2. Insert "pending" elements using the Jacobsthal sequence
// 	- The insertion order follows J(n): {1, 3, 5, 11, ...}
// 	- This means we insert in this order:
// 		- First pending element goes into position 1
// 		- Second pending element goes into position 3
// 		- Third pending element goes into position 5
// 		- And so on...
// By spacing out insertions this way, we preserve sorted order efficiently
// 	rather than doing a lot of unnecessary shifting.

// Summary
// 	1. Jacobsthal sequence spaces out insertions to reduce the number of shifts and comparisons needed.
// 	2. Binary insertion makes each insertion efficient by using binary search instead of scanning one-by-one.
// 	3. Combining both techniques leads to an efficient sorting method!

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

std::vector<size_t>	generateJacobSeq(size_t n);		// Create the Jacobsthal to help structure insertion efficiently. (where to insert)
std::vector<size_t>	getInsertionindex(size_t n);	// Build the actual insertion index list and decide where to insert.

template <typename Iter, typename T>				// 用二分法尋找比較快
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