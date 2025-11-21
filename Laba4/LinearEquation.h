#ifndef LINEAREQUATION_H
#define LINEAREQUATION_H

#include <iostream>
#include "Equation.h"

class LinearEquation :public Equation {
private:
	double a;
	double b;
public:
	LinearEquation(double = 0, double = 0);
	LinearEquation(const LinearEquation&);
	LinearEquation(LinearEquation&&) noexcept;
	LinearEquation& operator=(const LinearEquation&);
	LinearEquation& operator=(LinearEquation&&) noexcept;
	void solve() override;
	void print() override;
	double getA() const;
	double getB() const;
	bool hasInfiniteSolutions() const;
	bool conditionBGreaterThanA() const;
	bool has_solution()override;
};
#endif