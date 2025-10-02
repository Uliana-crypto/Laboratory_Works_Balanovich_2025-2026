#include "Complex.h"

void Input(Complex& c) {
    std::cout << "Enter real part: ";
    if (!(std::cin >> c.rePart)) {
        throw std::invalid_argument("Invalid input for real part");
    }

    std::cout << "Enter imaginary part: ";
    if (!(std::cin >> c.imPart)) {
        throw std::invalid_argument("Invalid input for imaginary part");
    }
}

Complex::Complex() {
    rePart = 0;
    imPart = 0;
}

Complex::Complex(double r, double i) {
    rePart = r;
    imPart = i;
}

std::ostream& operator<<(std::ostream& out, const Complex& c) {
    if (c.imPart == 0) {
        out << c.rePart;
    }
    else if (c.rePart == 0) {
        out << c.imPart << "i";
    }
    else {
        out << c.rePart;
        if (c.imPart > 0) {
            out << " + " << c.imPart << "i";
        }
        else {
            out << " - " << std::abs(c.imPart) << "i";
        }
    }
    return out;
}

void Complex::Print() const {
    std::cout << *this << "\n";
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

Complex Complex::operator+=(const Complex& other) {
    rePart += other.rePart;
    imPart += other.imPart;
    return *this;
}

Complex Complex::operator-() const {
    return Complex(-rePart, -imPart);
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

bool Complex::operator==(const Complex& other) const {
    return rePart == other.rePart && imPart == other.imPart;
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other);
}

double Complex::Abs() const {
    return std::sqrt(rePart * rePart + imPart * imPart);
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

Complex Complex::MultiplyByConjugate() const {
    return *this * ~(*this);
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
    if (n < 0) {
        return Inverse().Pow(-n);
    }

    Complex result(1, 0);
    for (int64_t i = 0; i < n; ++i) {
        result = result * (*this);
    }
    return result;
}