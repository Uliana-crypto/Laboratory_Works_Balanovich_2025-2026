#include "Deque.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    try {
        std::cout << "Выберите тип данных для дека (1 - int, 2 - char): ";
        int choice{};
        std::cin >> choice;
        if (!std::cin) {
            throw std::runtime_error("ожидалось число");
        }

        if (choice == 1) {
            TDeque<int> dq;
            int n{};
            std::cout << "Введите количество элементов: ";
            std::cin >> n;
            if (!std::cin || n < 0) {
                throw std::runtime_error("ожидалось положительное число");
            }

            dq.InputElements(n);

            std::cout << "\nЭлементы дека: ";
            dq.Browse(Print<int>);
            std::cout << "\n";

            std::cout << "Инкрементируем все элементы:\n";
            dq.Browse(IncrementInt);
            dq.Print();
            std::cout << "\n";

            std::cout << "Удаление с начала и конца:\n";
            int removed{};
            if (dq.DelFront(removed))
                std::cout << "Удален с начала: " << removed << "\n";
            if (dq.DelRear(removed))
                std::cout << "Удален с конца: " << removed << "\n";

            std::cout << "Оставшиеся элементы: ";
            dq.Print();
            std::cout << "\n";

            if (!dq.IsEmpty()) {
                std::cout << "Элемент по индексу 0: " << dq.GetByIndex(0) << "\n";
                std::cout << "Изменим его на 999\n";
                dq.SetByIndex(999, 0);
                dq.Print();
                std::cout << "\n";

                std::cout << "Указатель на элемент по индексу 0: ";
                int* ptr = static_cast<int*>(dq.PtrByIndex(0));
                std::cout << *ptr << "\n";
            }

            std::cout << "Копирование:\n";
            TDeque<int> copy(dq);
            copy.Print();
            std::cout << "\n";

            std::cout << "Присваивание:\n";
            TDeque<int> assigned;
            assigned = dq;
            assigned.Print();
            std::cout << "\n";

            std::cout << "Пустой ли дек: " << (dq.IsEmpty() ? "да" : "нет") << "\n";
        }
        else if (choice == 2) {
            TDeque<char> dq;
            int n{};
            std::cout << "Введите количество символов: ";
            std::cin >> n;

            dq.InputElements(n);

            std::cout << "\nЭлементы дека: ";
            dq.Print();
            std::cout << "\n";

            std::cout << "Удаление с начала и конца:\n";
            char removed;
            if (dq.DelFront(removed))
                std::cout << "Удален с начала: " << removed << "\n";
            if (dq.DelRear(removed))
                std::cout << "Удален с конца: " << removed << "\n";

            std::cout << "Оставшиеся элементы: ";
            dq.Print();
            std::cout << "\n";

            if (!dq.IsEmpty()) {
                std::cout << "Элемент по индексу 0: " << dq.GetByIndex(0) << "\n";
                std::cout << "Изменим его на 'Z'\n";
                dq.SetByIndex('Z', 0);
                dq.Print();
                std::cout << "\n";

                std::cout << "Указатель на элемент по индексу 0: ";
                char* ptr = static_cast<char*>(dq.PtrByIndex(0));
                std::cout << *ptr << "\n";
            }

            std::cout << "Копирование:\n";
            TDeque<char> copy(dq);
            copy.Print();
            std::cout << "\n";

            std::cout << "Присваивание:\n";
            TDeque<char> assigned;
            assigned = dq;
            assigned.Print();
            std::cout << "\n";

            std::cout << "Пустой ли дек: " << (dq.IsEmpty() ? "да" : "нет") << "\n";
        }
        else {
            std::cout << "Неверный выбор типа\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    return 0;
}