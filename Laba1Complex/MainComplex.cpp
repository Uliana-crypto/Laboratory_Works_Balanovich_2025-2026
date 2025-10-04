#include "Complex.h"

int main() {
    try {
        Complex a;
        Complex b;

        try {
            a.ReadComplex();
            b.ReadComplex();
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << "\n";
            return 1;
        }

        std::cout << "\nResults:\n";
        std::cout << "a + b = " << (a + b) << "\n";
        std::cout << "a - b = " << (a - b) << "\n";
        std::cout << "a * b = " << (a * b) << "\n";

        try {
            std::cout << "a / b = " << (a / b) << "\n";
        }
        catch (const std::logic_error& e) {
            std::cout << e.what() << "\n";
        }

        std::cout << "~a = " << ~a << "\n";
        std::cout << "-a = " << -a << "\n";
        std::cout << "++a = " << ++a << "\n";
        std::cout << "a++ = " << a++ << "\n";
        std::cout << "--a = " << --a << "\n";
        std::cout << "a-- = " << a-- << "\n";
        std::cout << "a += b = " << (a += b) << "\n";
        std::cout << "a == b: " << (a == b ? "true" : "false") << "\n";
        std::cout << "a != b: " << (a != b ? "true" : "false") << "\n";
        std::cout << "abs(a) = " << a.Abs() << "\n";
        std::cout << "a = " << (a += 5) << "\n";
        std::cout << "a = " << (a *= 5) << "\n";
        std::cout << "a * ~a = " << a.MultiplyByConjugate() << "\n";
        int32_t power{};
        std::cout << "Enter integer power: ";
        std::cin >> power;
        std::cout << "a^" << power << " = " << a.Pow(power) << "\n";
    }

    catch (const std::invalid_argument& e) {
        std::cout << e.what() << "\n";
    }
    catch (const std::logic_error& e) {
        std::cout << e.what() << "\n";
    }

    return 0;
}