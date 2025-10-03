#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point);

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"

void testBsp(const Point &a, const Point &b, const Point &c,
			 const Point &p, bool expected)
{
	bool result = bsp(a, b, c, p);

	std::cout << "Test point (" << p.getX() << ", " << p.getY() << "): ";

	if (result == expected)
		std::cout << GREEN << "OK" << RESET;
	else
		std::cout << RED << "FAIL" << RESET;

	std::cout << " (result=" << (result ? "true" : "false")
			  << ", expected=" << (expected ? "true" : "false") << ")"
			  << std::endl;
}

int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	std::cout << YELLOW << "Triangle vertices: (0,0), (10,0), (0,10)\n"
			  << RESET;

	testBsp(a, b, c, Point(2, 2), true);
	testBsp(a, b, c, Point(5, 5), false);
	testBsp(a, b, c, Point(10, 0), false);
	testBsp(a, b, c, Point(0, 0), false);
	testBsp(a, b, c, Point(20, 20), false);
}
