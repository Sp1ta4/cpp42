#include "Point.hpp"

static float absf(float x)
{
	return (x < 0 ? -x : x);
}

static float area(const Point &p1, const Point &p2, const Point &p3)
{
	float area = (p1.getX() * (p2.getY() - p3.getY()) + p2.getX() * (p3.getY() - p1.getY()) + p3.getX() * (p1.getY() - p2.getY())) / 2.0f;
	return absf(area);
}

bool bsp(const Point &a, const Point &b, const Point &c, const Point &point)
{
	float d0 = area(a, b, c);
	float d1 = area(point, a, b);
	float d2 = area(point, b, c);
	float d3 = area(point, a, c);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return (false);

	float epsilon = 0.0001f;
	return absf((d1 + d2 + d3) - d0) < epsilon;
}
