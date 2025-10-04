#include "Complex.h"

Complex::Complex() : rePart(0), imPart(0) {}

Complex::Complex(double r, double i) : rePart(r), imPart(i) {}

void Complex::Set(double r, double i) {
    rePart = r;
    imPart = i;
}

void Complex::ReadComplex() {
    double r = 0.0;
    double i = 0.0;
    std::cout << "Enter real and imaginary part: " << '\n';
    if (!(std::cin >> r >> i)) {
        throw std::invalid_argument("Invalid input for complex number");
    }
    Set(r, i);
}

Complex operator+(const Complex& a, const Complex& b) {
    return Complex(a.rePart + b.rePart, a.imPart + b.imPart);
}

Complex operator*(const Complex& a, const Complex& b) {
    return Complex(a.rePart * b.rePart - a.imPart * b.imPart,
        a.rePart * b.imPart + a.imPart * b.rePart);
}

Complex operator~(const Complex& a) {
    return Complex(a.rePart, -a.imPart);
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    const double re = c.GetRealPart();
    const double im = c.GetImaginaryPart();

    if (im == 0) {
        out << re;
    }
    else if (re == 0) {
        out << im << "i";
    }
    else {
        out << re << (im > 0 ? " + " : " - ") << std::abs(im) << "i";
    }
    return out;
}

Complex Complex::operator-() const {
    return Complex(-rePart, -imPart);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(rePart - other.rePart, imPart - other.imPart);
}

Complex Complex::operator/(const Complex& other) const {
    double denominator = other.rePart * other.rePart + other.imPart * other.imPart;
    if (denominator == 0.0) {
        throw std::logic_error("Division by zero");
    }
    Complex conjugate = ~other;
    Complex numerator = *this * conjugate;
    return Complex(numerator.rePart / denominator, numerator.imPart / denominator);
}

Complex Complex::operator++() {
    ++rePart;
    return *this;
}

Complex Complex::operator--() {
    --rePart;
    return *this;
}

Complex Complex::operator++(int) {
    Complex temp = *this;
    ++(*this);
    return temp;
}

Complex Complex::operator--(int) {
    Complex temp = *this;
    --(*this);
    return temp;
}

Complex Complex::operator+=(const Complex& other) {
    rePart += other.rePart;
    imPart += other.imPart;
    return *this;
}

Complex& Complex::operator+=(double value) {
    rePart += value;
    return *this;
}

Complex& Complex::operator*=(double value) {
    rePart *= value;
    imPart *= value;
    return *this;
}

bool Complex::operator==(const Complex& other) const {
    return rePart == other.rePart && imPart == other.imPart;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

double Complex::Abs() const {
    return std::sqrt(rePart * rePart + imPart * imPart);
}

Complex Complex::MultiplyByConjugate() const {
    return *this * ~(*this);
}

double Complex::GetRealPart() const {
    return rePart;
}

double Complex::GetImaginaryPart() const {
    return imPart;
}

Complex Complex::Inverse() const {
    double denom = rePart * rePart + imPart * imPart;
    if (denom == 0.0) {
        throw std::logic_error("Cannot invert zero complex number");
    }
    return Complex(rePart / denom, -imPart / denom);
}

Complex Complex::Pow(int64_t n) const {
    if (n == 0) {
        return Complex(1, 0);
    }
    if (n < 0)
    {
        return Inverse().Pow(-n);
    }
    Complex result(1, 0);
    for (int64_t i = 0; i < n; ++i) {
        result = result * (*this);
    }
    return result;
}