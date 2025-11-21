#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H

#include <iostream>
#include "Equation.h"

class QuadraticEquation :public Equation {
private:
	double a;
	double b;
	double c;
public:
	QuadraticEquation(double = 0, double = 0, double = 0);
	QuadraticEquation(const QuadraticEquation&);
	QuadraticEquation(QuadraticEquation&&)noexcept;
	QuadraticEquation& operator=(const QuadraticEquation&);
	QuadraticEquation& operator=(QuadraticEquation&&)noexcept;
	void solve() override;
	void print() override;
	double getA() const;
	double getB() const;
	double getC() const;
	double disc() const;
	void solveLinear() const;
	bool has_solution()override;
	
};
#endif


