#ifndef EQUATION_H
#define EQUATION_H

#include <iostream>
#include <fstream>

class Equation {
public:
    virtual void solve() = 0;
    virtual void print() = 0;
    virtual bool has_solution() = 0;
};

void findNoSolutions(Equation** arr, int N);
int32_t countInfiniteSolutions(Equation** arr, int N);
void CheckOutputFile(std::ofstream& fout);
double getLeadingCoefficient(Equation* eq);
void findQuadraticsWithNegativeDiscriminant(Equation** arr, int N);
void quickSort(Equation** arr, int low, int high);
void findDownwardQuadratics(Equation** arr, int N);
void sortQuadraticsByLeadingCoefficient(Equation** arr, int N);
bool isPerfectSquareQuadratic(Equation* qe);
int32_t collectPerfectSquareQuadratics(Equation** arr, int N, Equation** result);
void findAndSortLinearEquationsByB(Equation** arr, int N);

#endif