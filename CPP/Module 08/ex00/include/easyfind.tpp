template <typename T>
typename T::iterator	easyfind(T &cont, int i)
{
	typename T::iterator	it;

	it = std::find(cont.begin(), cont.end(), i);
	if (it == cont.end())
		throw std::out_of_range("Value not found.");
	return it;
}