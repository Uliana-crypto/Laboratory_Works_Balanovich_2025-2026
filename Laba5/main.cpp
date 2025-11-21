#include <iostream>
#include "Person.h"
#include "Student.h"
#include "Professor.h"

int main() {
    const int max = 100;
    Person* people[max];
    int count{};
    int choice{};

    while (true) {
        try {
            std::cout << "\nMenu:\n";
            std::cout << "1. Enter a student\n";
            std::cout << "2. Enter a teacher\n";
            std::cout << "3. List students\n";
            std::cout << "4. List teachers\n";
            std::cout << "5. Finish work\n";
            std::cout << "Your choice: ";
            if (!(std::cin >> choice)) {
                throw std::invalid_argument("Menu choice must be a number");
            }
            std::cin.ignore();

            switch (choice) {
            case 1: {
                if (count < max) {
                    char name[256];
                    int course{};
                    int group{};
                    std::cout << "Enter student's full name: ";
                    std::cin.getline(name, 256);
                    if (isDigitsOnly(name)) {
                        throw std::invalid_argument("Name cannot be only digits");
                    }
                    std::cout << "Enter course: ";
                    std::cin >> course;
                    if (!(std::cin >> course)) {
                        throw std::invalid_argument("Course must be a number");
                    }
                    std::cout << "Enter group: ";
                    std::cin >> group;
                    if (!(std::cin >> group)) {
                        throw std::invalid_argument("Group must be a number");
                    }
                    std::cin.ignore();
                    people[count++] = new Student(name, course, group);
                }
                else {
                    std::cout << "Array overflowed\n";
                }
                break;
            }
            case 2: {
                if (count < max) {
                    char name[256];
                    char depart[256];
                    std::cout << "Enter the teacher's full name: ";
                    std::cin.getline(name, 256);
                    if (isDigitsOnly(name)) {
                        throw std::invalid_argument("Name cannot be only digits");
                    }
                    std::cout << "Enter the department: ";
                    std::cin.getline(depart, 256);
                    if (!isDigitsOnly(depart)) {
                        throw std::invalid_argument("Department cannot be only digits");
                    }
                    people[count++] = new Professor(name, depart);
                }
                else {
                    std::cout << "Array overflowed\n";
                }
                break;
            }
            case 3: {
                std::cout << "\nList of students:\n";
                for (int i = 0; i < count; i++) {
                    if (std::string(people[i]->getType()) == "Student") {
                        people[i]->print();
                        std::cout << "-----------------\n";
                    }
                }
                break;
            }
            case 4: {
                std::cout << "\nList of teachers:\n";
                for (int i = 0; i < count; i++) {
                    if (std::string(people[i]->getType()) == "Professor") {
                        people[i]->print();
                        std::cout << "-----------------\n";
                    }
                }
                break;
            }
            case 5:
                std::cout << "Termination\n";
                for (int i = 0; i < count; i++) {
                    delete people[i];
                }
                return 0;
            default:
                std::cout << "Invalid menu item\n";
            }
        }
        catch (const std::exception& ex) {
            std::cout << ex.what() << "\n";
        }
    }
}