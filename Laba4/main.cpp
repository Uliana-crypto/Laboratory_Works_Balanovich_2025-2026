#include <iostream>
#include <fstream>
#include "Equation.h"
#include "LinearEquation.h"
#include "QuadraticEquation.h"

int main() {
    int N{};
    std::cout << "Enter the number of equations: ";
    std::cin >> N;

    Equation** arr = new Equation * [N];
    for (int i = 0; i < N; i++) {
        int type;
        std::cout << "Equation #" << i + 1 << ": Choose type (1 - Linear, 2 - Quadratic): ";
        std::cin >> type;

        if (type == 1) {
            double a, b;
            std::cout << "Enter coefficients a and b for ax + b = 0: ";
            std::cin >> a >> b;
            arr[i] = new LinearEquation(a, b);
        }
        else if (type == 2) {
            double a, b, c;
            std::cout << "Enter coefficients a, b, c for ax^2 + bx + c = 0: ";
            std::cin >> a >> b >> c;
            arr[i] = new QuadraticEquation(a, b, c);
        }
        else {
            std::cout << "Invalid type, defaulting to Linear (0x+0=0)\n";
            arr[i] = new LinearEquation(0, 0);
        }
    }

    std::ofstream out("Equations.txt");
    try {
        CheckOutputFile(out);
    }
    catch (const std::runtime_error& e) {
        std::cout << e.what() << "\n";
    }

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1) Find all equations with no solutions\n";
        std::cout << "2) Count equations with infinitely many solutions\n";
        std::cout << "3) Sort equations by leading coefficient\n";
        std::cout << "4) Find quadratic equations with negative discriminant\n";
        std::cout << "5) Find quadratic equations with downward branches\n";
        std::cout << "6) Find quadratic equations that are perfect squares (sorted by leading coefficient)\n";
        std::cout << "7) Find linear equations with b > a (sorted by descending b)\n";
        std::cout << "0) Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Equations with no solutions:\n";
            findNoSolutions(arr, N);
            break;
        case 2:
            std::cout << "Number of equations with infinitely many solutions: "
                << countInfiniteSolutions(arr, N) << "\n";
            break;
        case 3:
            sortQuadraticsByLeadingCoefficient(arr, N);
            std::cout << "Equations sorted by leading coefficient:\n";
            for (int i = 0; i < N; i++) arr[i]->print();
            break;
        case 4:
            std::cout << "Quadratic equations with negative discriminant:\n";
            for (int i = 0; i < N; i++) {
                QuadraticEquation* qe = dynamic_cast<QuadraticEquation*>(arr[i]);
                if (qe && qe->disc() < 0) qe->print();
            }
            break;
        case 5:
            std::cout << "Quadratic equations with downward branches:\n";
            findDownwardQuadratics(arr, N);
            break;
        case 6: {
            Equation** result = new Equation * [N];
            int count = collectPerfectSquareQuadratics(arr, N, result);
            if (count > 0) {
                quickSort(result, 0, count - 1);
                std::cout << "Perfect square quadratics sorted by leading coefficient:\n";
                for (int i = 0; i < count; i++) result[i]->print();
            }
            else {
                std::cout << "No perfect square quadratics found.\n";
            }
            delete[] result;
            break;
        }
        case 7:
            std::cout << "Linear equations with b > a (sorted by descending b):\n";
            findAndSortLinearEquationsByB(arr, N);
            break;
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    for (int i = 0; i < N; i++) {
        delete arr[i];
    }
    delete[] arr;

    return 0;
}
