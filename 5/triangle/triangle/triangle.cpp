#include <iostream>
#include <cmath>

class Point {
public:
	int x, y;

	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
};

class Figure {
public:
	virtual bool checkIntersection(const Point& point) { return false; };
};

class Triangle : public Figure {
private:
	int sign(const Point& p1, const Point& p2, const Point& p3)
	{
		return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
	}

public:
	Point firstPoint, secondPoint, thirdPoint;

	Triangle(Point first, Point second, Point third)
		: firstPoint(first), secondPoint(second), thirdPoint(third) {

	}

	bool checkIntersection(const Point& pt)
	{
		int d1, d2, d3;
		bool has_neg, has_pos;

		d1 = sign(pt, firstPoint, secondPoint);
		d2 = sign(pt, secondPoint, thirdPoint);
		d3 = sign(pt, thirdPoint, firstPoint);

		has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
		has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

		return !(has_neg && has_pos);
	}
};

int main() {

	setlocale(LC_ALL, "Russian");
	Point point1(0, 0);
	Point point2(0, 40);
	Point point3(40, 40);

	Triangle triangle(point1, point2, point3);

	Point testPoint(2, 25);
	if (triangle.checkIntersection(testPoint)) {
		std::cout << "Точка находится внутри треугольника." << std::endl;
	}
	else {
		std::cout << "Точка не находится внутри треугольника." << std::endl;
	}

	return 0;
}
