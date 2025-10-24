#include "BooksLibrary.h"
#include <windows.h> 

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    BookList library;
    size_t choice;

    do {
        std::cout << "\nМеню библиотеки:\n";
        std::cout << "1. Добавить книгу\n";
        std::cout << "2. Выдать книгу\n";
        std::cout << "3. Вернуть книгу\n";
        std::cout << "4. Показать все книги\n";
        std::cout << "5. Добавить книгу и сохранить в файл\n";
        std::cout << "6. Прочитать книги из файла и вывести на экран\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите пункт: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный ввод. Попробуйте снова\n";
            continue;
        }

        try {
            switch (choice) {
            case 1: {
                Book b;
                std::cout << "Введите УДК: ";
                std::cin >> b.UDK;
                std::cin.ignore();

                std::cout << "Введите автора: ";
                std::getline(std::cin, b.Author);

                std::cout << "Введите название: ";
                std::getline(std::cin, b.Title);

                std::cout << "Введите год издания: ";
                std::cin >> b.Year;

                std::cout << "Введите количество экземпляров: ";
                std::cin >> b.Count;

                library.AddBook(b);
                std::cout << "Книга успешно добавлена\n";
                break;
            }
            case 2: {
                size_t udk;
                std::cout << "Введите УДК книги для выдачи: ";
                std::cin >> udk;
                library.IssueBook(udk);
                break;
            }
            case 3: {
                size_t udk;
                std::cout << "Введите УДК книги для возврата: ";
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
                std::cout << "Выход из программы\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова\n";
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << "\n";
        }
    } while (choice != 0);

    return 0;
}
