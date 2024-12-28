#pragma once

# include <iostream>	// cout
# include <iomanip>		// setprecision for double

template <typename T>
void	iter(T *arr, int size, void (*f)(T))
{
	for (int i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

// Need the (*f)(T &) and (*f)(const T &) version,
// because the functions below may take T & or const T & as an argument.
template <typename T>
void	iter(T *arr, int size, void (*f)(T &))
{
	for (int i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

template <typename T>
void	iter(const T *arr, int size, void (*f)(const T &))
{
	for (int i = 0; i < size; i++)
	{
		f(arr[i]);
	}
}

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
void	print_one_const(const T &element)
{
	std::cout << std::fixed <<std::setprecision(2) << element << std::endl;
}

template <typename T>
void	print_next(T element)
{
	std::cout << std::fixed <<std::setprecision(2) << element + 1 << std::endl;
}