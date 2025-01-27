#pragma once

# include <iostream>	// cout
# include <iomanip>		// setprecision for double

template <typename T, typename F>
void	iter(T *arr, int size, F f)
{
	for (int i = 0; i < size; i++)
		f(arr[i]);
}
// No need the (*f)(T &) and (*f)(const T &) version or iter(),
// because typename F templatizes whatever resembles a function,
// taking T & and const T & as an argument.

template <typename T>
void	triple(T &element)
{
	element *= 3;
}

template <typename T>
void	print_one(T &element)
{
	std::cout << std::fixed <<std::setprecision(2) << element << std::endl;
}

template <typename T>
void	print_next(T element)
{
	std::cout << std::fixed <<std::setprecision(2) << element + 1 << std::endl;
}