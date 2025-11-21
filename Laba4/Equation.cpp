#include "Equation.h"
#include "LinearEquation.h"
#include "QuadraticEquation.h"
#include <iostream>

void findNoSolutions(Equation** arr, int N) {
    bool found = false;
    for (int i = 0; i < N; i++) {
        if (!arr[i]->has_solution()) {
            arr[i]->print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No equations without solutions found.\n";
    }
}

int32_t countInfiniteSolutions(Equation** arr, int N) {
    int count{};
    for (int i = 0; i < N; i++) {
        LinearEquation* le = dynamic_cast<LinearEquation*>(arr[i]);
        if (le != nullptr && le->hasInfiniteSolutions()) {
            count++;
        }
    }
    return count;
}

void CheckOutputFile(std::ofstream& fout) {
    if (!fout.good()) {
        throw std::runtime_error("File does not exist\n");
    }
    if (!fout) {
        throw std::runtime_error("Output file error\n");
    }
}

double getLeadingCoefficient(Equation* eq) {
    LinearEquation* le = dynamic_cast<LinearEquation*>(eq);
    if (le != nullptr) {
        return le->getA();
    }
    QuadraticEquation* qe = dynamic_cast<QuadraticEquation*>(eq);
    if (qe != nullptr) {
        return qe->getA();
    }
    return 0;
}

int partition(Equation** arr, int low, int high) {
    double pivot = getLeadingCoefficient(arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (getLeadingCoefficient(arr[j]) <= pivot) {
            i++;
            Equation* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Equation* temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(Equation** arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void findDownwardQuadratics(Equation** arr, int N) {
    bool found = false;
    for (int i = 0; i < N; ++i) {
        QuadraticEquation* qe = dynamic_cast<QuadraticEquation*>(arr[i]);
        if (qe != nullptr && qe->getA() < 0.0) {
            qe->print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No downward quadratic equations found.\n";
    }
}

void sortQuadraticsByLeadingCoefficient(Equation** arr, int N) {
    Equation** quadratics = new Equation * [N];
    int quadCount = 0;

    for (int i = 0; i < N; i++) {
        QuadraticEquation* qe = dynamic_cast<QuadraticEquation*>(arr[i]);
        if (qe != nullptr) {
            quadratics[quadCount++] = arr[i];
        }
    }

    if (quadCount > 0) {
        quickSort(quadratics, 0, quadCount - 1);
        std::cout << "Quadratic equations sorted by leading coefficient:\n";
        for (int i = 0; i < quadCount; i++) {
            quadratics[i]->print();
        }
    }
    else {
        std::cout << "No quadratic equations found.\n";
    }

    delete[] quadratics;
}

bool isPerfectSquareQuadratic(Equation* eq) {
    QuadraticEquation* qe = dynamic_cast<QuadraticEquation*>(eq);
    if (qe == nullptr || qe->getA() == 0) {
        return false;
    }
    double a = qe->getA();
    double b = qe->getB();
    double c = qe->getC();

    double discriminant = b * b - 4 * a * c;
    return std::abs(discriminant) < 1e-9;
}

int32_t collectPerfectSquareQuadratics(Equation** arr, int N, Equation** result) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (isPerfectSquareQuadratic(arr[i])) {
            result[count++] = arr[i];
        }
    }
    return count;
}

void findQuadraticsWithNegativeDiscriminant(Equation** arr, int N) {
    bool found = false;
    for (int i = 0; i < N; i++) {
        QuadraticEquation* qe = dynamic_cast<QuadraticEquation*>(arr[i]);
        if (qe && qe->getA() != 0 && qe->disc() < 0) {
            qe->print();
            found = true;
        }
    }
    if (!found) {
        std::cout << "No quadratic equations with negative discriminant found.\n";
    }
}

void findAndSortLinearEquationsByB(Equation** arr, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        LinearEquation* le = dynamic_cast<LinearEquation*>(arr[i]);
        if (le != nullptr && le->conditionBGreaterThanA()) {
            count++;
        }
    }

    if (count == 0) {
        std::cout << "No linear equations with b > a found.\n";
        return;
    }
    LinearEquation** filtered = new LinearEquation * [count];
    int index = 0;
    for (int i = 0; i < N; i++) {
        LinearEquation* le = dynamic_cast<LinearEquation*>(arr[i]);
        if (le != nullptr && le->conditionBGreaterThanA()) {
            filtered[index++] = le;
        }
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (filtered[i]->getB() < filtered[j]->getB()) {
                LinearEquation* temp = filtered[i];
                filtered[i] = filtered[j];
                filtered[j] = temp;
            }
        }
    }
    std::cout << "Linear equations with b > a (sorted by descending b):\n";
    for (int i = 0; i < count; i++) {
        filtered[i]->print();
    }

    delete[] filtered;
}