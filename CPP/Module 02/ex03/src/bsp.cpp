#include "Point.hpp"

Fixed	Area(const Point a, const Point b, const Point c)
{
	Fixed	area;

	area = ((b.getx() - a.getx()) * (c.gety() - a.gety()) \
			- (b.gety() - a.gety()) * (c.getx() - a.getx())) / 2;
	if (area < 0)
		return area * Fixed(-1);
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	A_abc = Area(a, b, c);
	Fixed	A_pab = Area(point, a, b);
	Fixed	A_pbc = Area(point, b, c);
	Fixed	A_pac = Area(point, a, c);

	// std::cout << std::endl;
	// std::cout << "A_abc = " << A_abc << std::endl;
	// std::cout << "A_pab = " << A_pab << std::endl;
	// std::cout << "A_pbc = " << A_pbc << std::endl;
	// std::cout << "A_pac = " << A_pac << std::endl;

	if (A_pab == 0 || A_pbc == 0 || A_pac == 0 \
	|| (A_abc != A_pab + A_pbc + A_pac))
		return false;
	return true;
}