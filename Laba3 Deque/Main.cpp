#include "Deque.h"

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    try {
        std::cout << "�������� ��� ������ ��� ���� (1 - int, 2 - char): ";
        int choice{};
        std::cin >> choice;
        if (!std::cin) {
            throw std::runtime_error("��������� �����");
        }

        if (choice == 1) {
            TDeque<int> dq;
            int n{};
            std::cout << "������� ���������� ���������: ";
            std::cin >> n;
            if (!std::cin || n < 0) {
                throw std::runtime_error("��������� ������������� �����");
            }

            dq.InputElements(n);

            std::cout << "\n�������� ����: ";
            dq.Browse(Print<int>);
            std::cout << "\n";

            std::cout << "�������������� ��� ��������:\n";
            dq.Browse(IncrementInt);
            dq.Print();
            std::cout << "\n";

            std::cout << "�������� � ������ � �����:\n";
            int removed{};
            if (dq.DelFront(removed))
                std::cout << "������ � ������: " << removed << "\n";
            if (dq.DelRear(removed))
                std::cout << "������ � �����: " << removed << "\n";

            std::cout << "���������� ��������: ";
            dq.Print();
            std::cout << "\n";

            if (!dq.IsEmpty()) {
                std::cout << "������� �� ������� 0: " << dq.GetByIndex(0) << "\n";
                std::cout << "������� ��� �� 999\n";
                dq.SetByIndex(999, 0);
                dq.Print();
                std::cout << "\n";

                std::cout << "��������� �� ������� �� ������� 0: ";
                int* ptr = static_cast<int*>(dq.PtrByIndex(0));
                std::cout << *ptr << "\n";
            }

            std::cout << "�����������:\n";
            TDeque<int> copy(dq);
            copy.Print();
            std::cout << "\n";

            std::cout << "������������:\n";
            TDeque<int> assigned;
            assigned = dq;
            assigned.Print();
            std::cout << "\n";

            std::cout << "������ �� ���: " << (dq.IsEmpty() ? "��" : "���") << "\n";
        }
        else if (choice == 2) {
            TDeque<char> dq;
            int n{};
            std::cout << "������� ���������� ��������: ";
            std::cin >> n;

            dq.InputElements(n);

            std::cout << "\n�������� ����: ";
            dq.Print();
            std::cout << "\n";

            std::cout << "�������� � ������ � �����:\n";
            char removed;
            if (dq.DelFront(removed))
                std::cout << "������ � ������: " << removed << "\n";
            if (dq.DelRear(removed))
                std::cout << "������ � �����: " << removed << "\n";

            std::cout << "���������� ��������: ";
            dq.Print();
            std::cout << "\n";

            if (!dq.IsEmpty()) {
                std::cout << "������� �� ������� 0: " << dq.GetByIndex(0) << "\n";
                std::cout << "������� ��� �� 'Z'\n";
                dq.SetByIndex('Z', 0);
                dq.Print();
                std::cout << "\n";

                std::cout << "��������� �� ������� �� ������� 0: ";
                char* ptr = static_cast<char*>(dq.PtrByIndex(0));
                std::cout << *ptr << "\n";
            }

            std::cout << "�����������:\n";
            TDeque<char> copy(dq);
            copy.Print();
            std::cout << "\n";

            std::cout << "������������:\n";
            TDeque<char> assigned;
            assigned = dq;
            assigned.Print();
            std::cout << "\n";

            std::cout << "������ �� ���: " << (dq.IsEmpty() ? "��" : "���") << "\n";
        }
        else {
            std::cout << "�������� ����� ����\n";
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << "\n";
    }
    return 0;
}