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
	Point operator+(const Point& other) const {
		return Point(x + other.x, y + other.y);
	}
	bool operator<(const Point& other) const {
		if (x < other.x) {
			return true;
		}
		else if (x == other.x && y < other.y) {
			return true;
		}
		return false;
	}

	bool operator==(const Point& other) const {
		return x == other.x && y == other.y;
	}

	bool operator!=(const Point& other) const {
		return !(*this == other);
	}
	int x;
	int y;
};
