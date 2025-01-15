#pragma once

# include <iostream>	// cout
# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &cont, int i);

# include "easyfind.tpp"

// typename T::iterator:
// 	the "iterator" type is under the type "T"
// T &cont:
// 	a reference to a T-type container