#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
private:
    double rePart;
    double imPart;

public:
    Complex();
    Complex(double r, double i);
    friend void Input(Complex& c);
    Complex Pow(int64_t n) const;
    Complex Inverse() const;

    Complex operator-(const Complex& other) const;
    Complex operator/(const Complex& other) const;
    Complex operator+=(const Complex& other);
    Complex& operator+=(double value);
    Complex& operator*=(double value);
    Complex MultiplyByConjugate() const;

    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend Complex operator~(const Complex& a);

    Complex operator-() const;
    friend Complex operator~(const Complex& a);

    Complex operator++();
    Complex operator--();
    Complex operator++(int);
    Complex operator--(int);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);

    double Abs() const;
    void Print() const;
};

inline Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.rePart + b.rePart, a.imPart + b.imPart);
}

inline Complex operator*(const Complex& a, const Complex& b) {
    return Complex(a.rePart * b.rePart - a.imPart * b.imPart, a.rePart * b.imPart + a.imPart * b.rePart);
}

inline Complex operator~(const Complex& a) {
    return Complex(a.rePart, -a.imPart);
}

#endif