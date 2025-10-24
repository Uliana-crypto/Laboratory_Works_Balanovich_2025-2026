#include "header.h"
#include <iostream>
#include <string>
#include <clocale>

template<typename T>
void RunStackDemo() {
    MyStack<T> original;

    size_t numElements{};
    std::cout << "Сколько элементов добавить в стек? ";
    std::cin >> numElements;

    std::cout << "Введите " << numElements << " элементов типа " << typeid(T).name() << ":\n";
    for (size_t i = 0; i < numElements; ++i) {
        T value{};
        std::cin >> value;
        original.Push(value);
    }

    std::cout << "Верхний элемент оригинального стека: " << original.Peek() << "\n";

    MyStack<T> copy = original;
    std::cout << "Верхний элемент копии: " << copy.Peek() << "\n";

    copy.Pop();
    std::cout << "После Pop копии: " << copy.Peek() << "\n";
    std::cout << "Оригинал не изменился: " << original.Peek() << "\n";

    MyStack<T> moved = std::move(original);
    std::cout << "Верхний элемент перемещённого стека: " << moved.Peek() << "\n";
    std::cout << "Оригинал пуст после перемещения: " << std::boolalpha << original.IsEmpty() << "\n";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    try {
        std::cout << "Выберите тип данных:\n";
        std::cout << "1 — int\n";
        std::cout << "2 — double\n";
        std::cout << "3 — std::string\n";
        int32_t choice{};
        std::cin >> choice;

        switch (choice) {
        case 1: RunStackDemo<int>(); break;
        case 2: RunStackDemo<double>(); break;
        case 3: RunStackDemo<std::string>(); break;
        default: std::cerr << "Неверный выбор типа.\n"; return 1;
        }

        std::cin.ignore();
        std::string brackets;
        std::cout << "Введите строку со скобками для проверки: ";
        std::getline(std::cin, brackets);

        MyStack<char> bracketStack;
        bool balanced = bracketStack.CheckBalancedBrackets(brackets);
        std::cout << "Скобки " << (balanced ? "сбалансированы" : "не сбалансированы") << "\n";

        size_t count{};
        std::cout << "Введите количество вагонов: ";
        std::cin >> count;

        MyStack<std::string> train;

        std::cout << "Введите цвета вагонов (\"белый\" или \"чёрный\"):\n";
        for (size_t i = 0; i < count; ++i) {
            std::string color;
            std::cin >> color;

            if (color != "белый" && color != "чёрный") {
                std::cerr << "Недопустимый цвет: " << color << ". Допустимы только \"белый\" и \"чёрный\".\n";
                return 1;
            }

            train.Push(color);
        }

        MyStack<std::string> sorted = train.SortTrainAlternating(train);

        std::cout << "\nОтсортированные вагоны (белый-чёрный):\n";
        while (!sorted.IsEmpty()) {
            std::cout << sorted.Peek() << "\n";
            sorted.Pop();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }

    return 0;
}
