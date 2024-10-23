#include "Point.hpp"
#include <iostream>

// Needs to be const, cuz In C++, string literals (like "Hello")
// are treated as arrays of const char
const char	*side(bool input)
{
	if (input == false)
		return "NOT inside";
	return "inside";
}

int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point p1(1, 1);
	Point p2(-10, -10);
	Point p3(2.0f, 3.0f);
	Point p4(5, 0);
	Point p5(5, 5);

	std::cout << "Triangle with the vertices a(0, 0), b(10, 0) and c(0, 10)." << std::endl;
	std::cout << "__________________________________________________________" << std::endl;
	std::cout << "p1(1, 1)       is " << side(bsp(a, b, c, p1)) << " the triangle."<< std::endl;
	std::cout << "p2(-10, -10)   is " << side(bsp(a, b, c, p2)) << " the triangle."<< std::endl;
	std::cout << "p3(2.0f, 3.0f) is " << side(bsp(a, b, c, p3)) << " the triangle."<< std::endl;
	std::cout << "p4(5, 0)       is " << side(bsp(a, b, c, p4)) << " the triangle."<< std::endl;
	std::cout << "p5(5, 5)       is " << side(bsp(a, b, c, p5)) << " the triangle."<< std::endl;

	return 0;
}