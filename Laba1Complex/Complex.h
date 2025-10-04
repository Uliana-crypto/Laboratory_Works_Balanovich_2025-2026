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

    void Set(double r, double i);
    double GetRealPart() const;
    double GetImaginaryPart() const;

    void ReadComplex();

    Complex Pow(int64_t n) const;
    Complex Inverse() const;
    Complex MultiplyByConjugate() const;
    double Abs() const;

    Complex operator-() const;
    Complex operator-(const Complex& other) const;
    Complex operator/(const Complex& other) const;

    Complex operator++();
    Complex operator--();
    Complex operator++(int);
    Complex operator--(int);

    Complex operator+=(const Complex& other);
    Complex& operator+=(double value);
    Complex& operator*=(double value);

    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    friend Complex operator+(const Complex& a, const Complex& b);
    friend Complex operator*(const Complex& a, const Complex& b);
    friend Complex operator~(const Complex& a);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif 

