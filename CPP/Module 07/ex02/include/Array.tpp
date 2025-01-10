template <typename T>
Array<T>::Array(void): _size(0), _arr(new T[_size]())
{
	// std::cout << "[Array] Default constructor called." << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n), _arr(new T[_size]())
{
	// std::cout << "[Array] Parameterized constructor called." << std::endl;
}

template <typename T>
Array<T>::Array(const Array& src)
{
	// std::cout << "[Array] Copy constructor called." << std::endl;
	*this = src;
}

template <typename T>
Array<T>&	Array<T>::operator = (const Array<T>& src)
{
	// std::cout << "[Array] Assignment constructor called." << std::endl;
	if (this != &src)
	{	
		delete[] this->_arr;
		this->_size = src._size;
		this->_arr = new T[this->_size]();
		for (unsigned int i = 0; i < this->_size; i++)
			this->_arr[i] = src._arr[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array(void)
{
	// std::cout << "[ARRAY] Destructor called." << std::endl;
	delete[] this->_arr;
}

template <typename T>
T&	Array<T>::operator [] (unsigned int i)
{
	if (i >= this->_size)
		throw Array<T>::OutOfRangeException();
	return this->_arr[i];
}

template <typename T>
const T&	Array<T>::operator [] (unsigned int i) const
{
	if (i >= this->_size)
		throw Array<T>::OutOfRangeException();
	return this->_arr[i];
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return this->_size;
}

template <typename T>
const char*	Array<T>::OutOfRangeException::what() const throw()
{
	return "[Exception] Index out of range.";
}

template <typename T>
std::ostream&	operator << (std::ostream &o, const Array<T> &src)
{
	for (unsigned int i = 0; i < src.size(); i++)
		o << "\tArray " << i << ": " << src[i] << std::endl;
	return o;
}