#pragma once

# include <iostream>	// cout
# include <stack>

// A container in C++ is a conceptual "box" designed to
// 	store and manage collections of objects or data elements.
// All standard containers in C++ are templates,
// 	meaning their syntax is generally Container<Type>.

template <typename T>
class	MutantStack: public std::stack<T>
{
	public:
		MutantStack(void);										// Default constructor
		MutantStack(const MutantStack<T>& src);					// Copy constructor
		MutantStack&	operator = (const MutantStack& src);	// Assignment operator
		~MutantStack(void);										// Destructor

		/* * * * * * * * Define iterators * * * * * * * */
		typedef typename std::stack<T>::container_type::iterator		iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		// The std::stack is an adapter class. It is not a container itself
		// 	but wraps around an underlying container (like std::deque or std::vector).
		// container_type:
		// Inside the std::stack class, there is a type alias called container_type.
		// 	This alias refers to the actual type of the underlying container used by the stack.
		// 	ie. an alias for the actual underlying container type that the stack uses to store its elements
		// typedef:
		// 	defines the type alias (the name for the new type)
		// 	ie. typedef unsigned int	uint;
		// typename:
		// 	stating that what follows is the very type being defined

		// Define functions
		iterator		begin(void);
		iterator		end(void);
		const_iterator	begin(void) const;
		const_iterator	end(void) const;
};

# include "MutantStack.tpp"