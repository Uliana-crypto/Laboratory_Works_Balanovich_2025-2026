#ifndef POINT3D_H
#define POINT3D_H

#include "Point2D.h"
#include <iostream>

class Point3D : public Point2D{
private:
	double z;
public:
	Point3D(double = 0, double = 0, double = 0);
	Point3D(const Point3D&);
	Point3D(Point3D&&) noexcept;
	~Point3D()=default;

	Point3D& operator=(const Point3D&);
	Point3D& operator=(Point3D&&);

	double getZ() const noexcept;

	Point3D& operator+=(const Point3D&);
	Point3D operator+(const Point3D&);

	void MoveOz(const double);

	friend std::ostream& operator<<(std::ostream&, const Point3D&);
	friend std::istream& operator>>(std::istream&, Point3D&);
};

Point3D::Point3D(double x, double y, double z) : Point2D(x,y), z(z) {}

Point3D::Point3D(const Point3D& init) : Point2D(init), z(init.z) {}

Point3D::Point3D(Point3D&& init) noexcept : Point2D(std::move(init)), z(init.z) {
	init.z = 0;
}

Point3D& Point3D::operator=(const Point3D& rhs) {
	if (this != &rhs) {
		Point2D::operator=(static_cast<const Point2D&>(rhs));
		z = rhs.z;
	}
	return *this;
}

Point3D& Point3D::operator=(Point3D&& rhs) {
	if (this != &rhs) {
		Point2D::operator=(std::move(rhs));
		z = rhs.z;
		rhs.z = 0;
	}
	return *this;
}

double Point3D::getZ() const noexcept {
	return z;
}

Point3D& Point3D::operator+=(const Point3D& other) {
	Point2D::operator+=(static_cast<const Point2D&>(other));
	this-> z += other.z;
	return *this;
}
Point3D Point3D::operator+(const Point3D& other) {
	Point3D result(*this);
	result += other;
	return result;
}

void Point3D::MoveOz(const double dz) {
	this->z += dz;
}

std::ostream& operator<<(std::ostream& os, const Point3D& point) {
	os << "(" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")";
	return os;
}

std::istream& operator>>(std::istream& is, Point3D& point) {
	is >> point.x >> point.y >> point.z;
	return is;
}

#endif
