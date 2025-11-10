#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

class Point2D {
protected:
	double x;
	double y;
public:
	Point2D(double = 0, double = 0);
	Point2D(const Point2D&) = default;
	Point2D(Point2D&&) = default;
	virtual ~Point2D()=default;

	Point2D& operator=(const Point2D&);
	Point2D& operator=(Point2D&&);

	double getX()const noexcept;
	double getY()const noexcept;

	Point2D& operator+=(const Point2D&);
	Point2D operator+(const Point2D&);

	void MoveOx(const double);
	void MoveOy(const double);

	friend std::ostream& operator<<(std::ostream&, const Point2D&);
	friend std::istream& operator>>(std::istream&, Point2D&);
};

Point2D::Point2D(double x, double y) :x(x), y(y) {}
//
//Point2D::Point2D(const Point2D& other) : x(other.x), y(other.y) {}
////
//Point2D::Point2D(Point2D&& other) :x(other.x), y(other.y) {
//	other.x = 0;
//	other.y = 0;
//}

std::ostream& operator<<(std::ostream& os, const Point2D& point) {
	os << "(" << point.x << ", " << point.y << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point2D& point) {
	is >> point.x >> point.y;
	return is;
}

double Point2D::getX()const noexcept {
	return x;
}

double Point2D::getY()const noexcept {
	return y;
}

void Point2D::MoveOx(const double dx) {
	this->x += dx;
}

void Point2D::MoveOy(const double dy) {
	this->y += dy;
}

Point2D& Point2D::operator+=(const Point2D& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Point2D Point2D::operator+(const Point2D& other) {
	Point2D result(*this);
	result += other;
	return result;
}

Point2D& Point2D::operator=(const Point2D& rhs) {
	if (this != &rhs) {
		this->x = rhs.x;
		this->y = rhs.y;
	}
	return *this;
}

Point2D& Point2D::operator=(Point2D&& rhs) {
	if (this != &rhs) {
		x = rhs.x;
		y = rhs.y;
		rhs.x = 0;
		rhs.y = 0;
	}
	return *this;
}
#endif