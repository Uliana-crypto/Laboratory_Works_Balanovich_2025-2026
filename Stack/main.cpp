#include "header.h"
#include <iostream>
#include <string>
#include <clocale>

template<typename T>
void RunStackDemo() {
    MyStack<T> original;

    size_t numElements{};
    std::cout << "������� ��������� �������� � ����? ";
    std::cin >> numElements;

    std::cout << "������� " << numElements << " ��������� ���� " << typeid(T).name() << ":\n";
    for (size_t i = 0; i < numElements; ++i) {
        T value{};
        std::cin >> value;
        original.Push(value);
    }

    std::cout << "������� ������� ������������� �����: " << original.Peek() << "\n";

    MyStack<T> copy = original;
    std::cout << "������� ������� �����: " << copy.Peek() << "\n";

    copy.Pop();
    std::cout << "����� Pop �����: " << copy.Peek() << "\n";
    std::cout << "�������� �� ���������: " << original.Peek() << "\n";

    MyStack<T> moved = std::move(original);
    std::cout << "������� ������� ������������� �����: " << moved.Peek() << "\n";
    std::cout << "�������� ���� ����� �����������: " << std::boolalpha << original.IsEmpty() << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    try {
        std::cout << "�������� ��� ������:\n";
        std::cout << "1 � int\n";
        std::cout << "2 � double\n";
        std::cout << "3 � std::string\n";
        int32_t choice{};
        std::cin >> choice;

        switch (choice) {
        case 1: RunStackDemo<int>(); break;
        case 2: RunStackDemo<double>(); break;
        case 3: RunStackDemo<std::string>(); break;
        default: std::cerr << "�������� ����� ����.\n"; return 1;
        }

        std::cin.ignore();
        std::string brackets;
        std::cout << "������� ������ �� �������� ��� ��������: ";
        std::getline(std::cin, brackets);

        MyStack<char> bracketStack;
        bool balanced = bracketStack.CheckBalancedBrackets(brackets);
        std::cout << "������ " << (balanced ? "��������������" : "�� ��������������") << "\n";

        size_t count{};
        std::cout << "������� ���������� �������: ";
        std::cin >> count;

        MyStack<std::string> train;

        std::cout << "������� ����� ������� (\"�����\" ��� \"������\"):\n";
        for (size_t i = 0; i < count; ++i) {
            std::string color;
            std::cin >> color;

            if (color != "�����" && color != "������") {
                std::cerr << "������������ ����: " << color << ". ��������� ������ \"�����\" � \"������\".\n";
                return 1;
            }

            train.Push(color);
        }

        MyStack<std::string> sorted = train.SortTrainAlternating(train);

        std::cout << "\n��������������� ������ (�����-������):\n";
        while (!sorted.IsEmpty()) {
            std::cout << sorted.Peek() << "\n";
            sorted.Pop();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "������: " << e.what() << "\n";
    }

    return 0;
}
