#include "BooksLibrary.h"
#include <windows.h> 

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    BookList library;
    size_t choice;

    do {
        std::cout << "\n���� ����������:\n";
        std::cout << "1. �������� �����\n";
        std::cout << "2. ������ �����\n";
        std::cout << "3. ������� �����\n";
        std::cout << "4. �������� ��� �����\n";
        std::cout << "5. �������� ����� � ��������� � ����\n";
        std::cout << "6. ��������� ����� �� ����� � ������� �� �����\n";
        std::cout << "0. �����\n";
        std::cout << "�������� �����: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "�������� ����. ���������� �����\n";
            continue;
        }

        try {
            switch (choice) {
            case 1: {
                Book b;
                std::cout << "������� ���: ";
                std::cin >> b.UDK;
                std::cin.ignore();

                std::cout << "������� ������: ";
                std::getline(std::cin, b.Author);

                std::cout << "������� ��������: ";
                std::getline(std::cin, b.Title);

                std::cout << "������� ��� �������: ";
                std::cin >> b.Year;

                std::cout << "������� ���������� �����������: ";
                std::cin >> b.Count;

                library.AddBook(b);
                std::cout << "����� ������� ���������\n";
                break;
            }
            case 2: {
                size_t udk;
                std::cout << "������� ��� ����� ��� ������: ";
                std::cin >> udk;
                library.IssueBook(udk);
                break;
            }
            case 3: {
                size_t udk;
                std::cout << "������� ��� ����� ��� ��������: ";
                std::cin >> udk;
                library.ReturnBook(udk);
                break;
            }
            case 4: {
                library.ShowBooks();
                break;
            }
            case 5: {
                try {
                    library.AddBookFromConsoleAndSave("InAndOutBooks.txt");
                }
                catch (const std::exception& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            }
            case 6: {
                try {
                    library.ReadAndDisplayFromFile("InAndOutBooks.txt");
                }
                catch (const std::exception& e) {
                    std::cout << e.what() << "\n";
                }
                break;
            }
            case 0:
                std::cout << "����� �� ���������\n";
                break;
            default:
                std::cout << "�������� �����. ���������� �����\n";
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}
