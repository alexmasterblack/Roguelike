#pragma once

class Point {
public:
	Point(int x, int y) :
		x(x),
		y(y) {}

	Point operator=(const Point& other) {
		x = other.x;
		y = other.y;
		return *this;
	}
	
	int x;
	int y;
};
