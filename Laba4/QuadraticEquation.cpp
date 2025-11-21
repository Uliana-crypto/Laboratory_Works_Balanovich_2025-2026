#include "QuadraticEquation.h"

QuadraticEquation::QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

QuadraticEquation::QuadraticEquation(const QuadraticEquation& other) : a(other.a), b(other.b), c(other.c) {}

QuadraticEquation::QuadraticEquation(QuadraticEquation&& other) noexcept : a(other.a), b(other.b), c(other.c) {
    other.a = 0;
    other.b = 0;
    other.c = 0;
}

QuadraticEquation& QuadraticEquation::operator=(const QuadraticEquation& other) {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
    }
    return *this;
}

QuadraticEquation& QuadraticEquation::operator=(QuadraticEquation&& other) noexcept {
    if (this != &other) {
        a = other.a;
        b = other.b;
        c = other.c;
        other.a = 0;
        other.b = 0;
        other.c = 0;
    }
    return *this;
}

void QuadraticEquation::solve() {
    if (a == 0) {
        solveLinear();
        return;
    }
    double D = disc();
    if (D < 0) {
        std::cout << "There are no real roots\n";
    }
    else if (D == 0) {
        std::cout << "There is one root: x = " << (-b) / (2 * a) << "\n";
    }
    else {
        double sqrtD = std::sqrt(D);
        double x1 = (-b - sqrtD) / (2 * a);
        double x2 = (-b + sqrtD) / (2 * a);
        std::cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";
    }
}

void QuadraticEquation::print() {
    if (a == 0 && b == 0 && c == 0) {
        std::cout << "0 = 0";
    }
    else {
        bool firstTerm = true;

        if (a != 0) {
            std::cout << a << "x^2";
            firstTerm = false;
        }

        if (b != 0) {
            if (!firstTerm) {
                std::cout << " ";
            }
            char sign = (b > 0) ? '+' : '-';
            if (firstTerm && b < 0) {
                std::cout << "-";
            }
            else if (!firstTerm) {
                std::cout << sign << " ";
            }
            std::cout << std::abs(b) << "x";
            firstTerm = false;
        }

        if (c != 0) {
            if (!firstTerm) {
                std::cout << " ";
            }
            char sign = (c > 0) ? '+' : '-';
            if (firstTerm && c < 0) {
                std::cout << "-";
            }
            else if (!firstTerm) {
                std::cout << sign << " ";
            }
            std::cout << std::abs(c);
            firstTerm = false;
        }

        if (firstTerm) {
            std::cout << "0";
        }
        std::cout << " = 0";
    }
    std::cout << "\n";
}

double QuadraticEquation::getA() const {
    return a; 
}
double QuadraticEquation::getB() const {
    return b;
}
double QuadraticEquation::getC() const {
    return c; 
}

double QuadraticEquation::disc() const{
    return (b * b - 4 * a * c);
}

void QuadraticEquation::solveLinear() const {
    if (b != 0) {
        std::cout << "Linear case: x = " << (-c) / b << "\n";
    }
    else {
        std::cout << "No solutions\n";
    }
}

bool QuadraticEquation::has_solution() {
    return !(a == 0 && b == 0 && c != 0);
}