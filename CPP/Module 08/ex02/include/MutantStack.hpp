#pragma once

# include <iostream>	// cout
# include <stack>

// A container in C++ is a conceptual "box" designed to
// 	store and manage collections of objects or data elements.
// All standard containers in C++ are templates,
// 	meaning their syntax is generally Container<Type>.

template <typename T, typename Container = std::deque<T> >
class	MutantStack: public std::stack<T, Container>
// The std::stack is an adapter class. It is not a container itself
// 	but wraps around an underlying container (like std::deque or std::vector).
{
	public:
		MutantStack(void): std::stack<T, Container>() {}						// Default constructor
		// The std::stack constructor doesn't require void as an argument; it just needs to be default-initialized.
		MutantStack(const MutantStack& src): std::stack<T, Container>(src) {}	// Copy constructor
		MutantStack&	operator = (const MutantStack& src)						// Assignment operator
		{
			std::stack<T, Container>::operator = (src);
			return *this;
		}
		~MutantStack(void) {}													// Destructor

		/* * * * * * * * Define iterators * * * * * * * */
		typedef typename Container::iterator		iterator;
		typedef typename Container::const_iterator	const_iterator;
		
		// typedef:
		// 	defines the type alias (the name for the new type)
		// 	ie. typedef unsigned int	uint;
		// typename:
		// 	stating that what follows is the very type being defined

		/* * * * * * * * Define functions * * * * * * * */
		iterator		begin(void) {return this->c.begin();}
		iterator		end(void) {return this->c.end();}
		const_iterator	begin(void) const {return this->c.begin();}
		const_iterator	end(void) const {return this->c.end();}
		// "c" is the name of the underlying container in std::stack.
		// 	By default, this container is of type std::deque, with iterators already available

		// "this->" is necessary, because
		// When you access private members in a class's own functions,
		// 	the compiler knows these members belong to the current class.
		// 	this-> is optional for clarity but not required
		// 	because the compiler assumes the reference is within the current class scope.
		// In the case of MutantStack, the c member belongs to the base class (std::stack), not MutantStack directly.
		// 	To clarify this inheritance relationship, you must explicitly qualify the member using this->c.
		// 	Without this->, the compiler does not automatically search in the base class's scope.
		// When dealing with inherited members, you often need
		// 	this-> or BaseClass:: to resolve ambiguities and clarify intent.
};

// container_type: (templated with Container, no longer needed)
// (before: typedef typename std::stack<T>::container_type::iterator		iterator;)
// Inside the std::stack class, there is a type alias called container_type.
// 	This alias refers to the actual type of the underlying container used by the stack.
// 	ie. an alias for the actual underlying container type that the stack uses to store its elements