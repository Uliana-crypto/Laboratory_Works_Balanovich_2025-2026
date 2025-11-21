#include "LinearEquation.h"


LinearEquation::LinearEquation(double a, double b) : a(a), b(b) {}

LinearEquation::LinearEquation(const LinearEquation& other) : a(other.a), b(other.b) {}

LinearEquation::LinearEquation(LinearEquation&& other) noexcept : a(other.a), b(other.b) {
	other.a = 0;
	other.b = 0;
}

LinearEquation& LinearEquation::operator=(const LinearEquation& other) {
	if (this != &other) {
		a = other.a;
		b = other.b;
	}
	return *this;
}

LinearEquation& LinearEquation::operator=(LinearEquation&& other) noexcept {
	if (this != &other) {
		a = other.a;
		b = other.b;
		other.a = 0;
		other.b = 0;
	}
	return *this;
}

void LinearEquation::solve() {
	if (a != 0) {
		std::cout << "x = " << (-b) / a << "\n";
	}
	else {
		if (b == 0) {
			std::cout << "Infinitely many solutions\n";
		}
		else {
			std::cout << "No solutions\n";
		}
	}
}

void LinearEquation::print() {
	if (a == 0 && b == 0) {
		std::cout << "0 = 0";
	}
	else if (a == 0) {
		std::cout << b << " = 0";
	}
	else {
		std::cout << a << "x";
		if (b != 0) {
			char sign = (b > 0) ? '+' : '-';
			std::cout << " " << sign << " " << std::abs(b);
		}
		std::cout << " = 0";
	}
	std::cout << "\n";
}

bool LinearEquation::has_solution() {
	return !(a == 0 && b != 0);
}

double LinearEquation::getA() const {
	return a;
}

double LinearEquation::getB() const{
	return b; 
}

bool LinearEquation::hasInfiniteSolutions() const {
	return (a == 0 && b == 0);
}

bool LinearEquation::conditionBGreaterThanA() const {
	return (b > a);
}
