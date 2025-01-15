template <typename T>
MutantStack<T>::MutantStack(void)
{
	// std::cout << "[MutantStack] Default constructor called." << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src)
{
	// std::cout << "[MutantStack] Copy constructor called." << std::endl;
	*this = src;
}

template <typename T>
MutantStack<T>&	MutantStack<T>::operator = (const MutantStack<T>& src)
{
	std::cout << "[MutantStack] Assignment constructor called." << std::endl;
	if (this != &src)
		this->c = src.c;
	return *this;
}
// "c" is the name of the underlying container in std::stack.
// 	By default, this container is of type std::deque, with iterators already available

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	// std::cout << "[MutantStack] Destructor called." << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return this->c.begin();
}
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

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return this->c.end();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return this->c.end();
}