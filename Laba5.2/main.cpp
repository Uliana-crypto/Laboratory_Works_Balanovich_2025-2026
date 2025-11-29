#include <iostream>
#include "StudentAfterSecondSession.h"
#include "StudentAfterFirstSession.h"

int main() {
    Student* students[100];
    int studentCount{};
    int choice{};

    do {
        std::cout << "\n=== Student Management System ===\n";
        std::cout << "1. Add Student After First Session\n";
        std::cout << "2. Add Student After Second Session\n";
        std::cout << "3. Display All Students\n";
        std::cout << "4. Calculate Group Average (First Session)\n";
        std::cout << "5. Calculate Group Average (Second Session)\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;

        if (choice == 1) {
            if (studentCount >= 100) {
                std::cout << "Maximum number of students reached\n";
                continue;
            }

            std::string name;
            int course{};
            int group{};
            int recordBookNum{};
            int grades[4];

            std::cout << "\n--- Adding Student After First Session ---\n";
            std::cout << "Enter name: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            std::cout << "Enter course (1-6): ";
            std::cin >> course;

            std::cout << "Enter group: ";
            std::cin >> group;

            std::cout << "Enter record book number: ";
            std::cin >> recordBookNum;

            std::cout << "Enter 4 grades (1-10): ";

            for (int i = 0; i < 4; i++) {
                std::cin >> grades[i];
            }

            try {
                students[studentCount] = new StudentAfterFirstSession(name, course, group, recordBookNum, grades);
                studentCount++;
                std::cout << "Student added successfully\n";
            }
            catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }
        }
        else if (choice == 2) {
            if (studentCount >= 100) {
                std::cout << "Maximum number of students reached\n";
                continue;
            }

            std::string name;
            int course{};
            int group{};
            int recordBookNum{};
            int grades1[4];
            int grades2[5];

            std::cout << "\n--- Adding Student After Second Session ---\n";
            std::cout << "Enter name: ";
            std::cin.ignore();
            std::getline(std::cin, name);

            std::cout << "Enter course (1-6): ";
            std::cin >> course;

            std::cout << "Enter group: ";
            std::cin >> group;

            std::cout << "Enter record book number: ";
            std::cin >> recordBookNum;

            std::cout << "Enter 4 grades for first session (1-10): ";
            for (int i = 0; i < 4; i++) {
                std::cin >> grades1[i];
            }

            std::cout << "Enter 5 grades for second session (1-10): ";
            for (int i = 0; i < 5; i++) {
                std::cin >> grades2[i];
            }

            try {
                students[studentCount] = new StudentAfterSecondSession(name, course, group, recordBookNum, grades1, grades2);
                studentCount++;
                std::cout << "Student added successfully\n";
            }
            catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }
        }
        else if (choice == 3) {
            std::cout << "\n--- All Students ---\n";
            if (studentCount == 0) {
                std::cout << "No students in the system\n";
            }
            else {
                for (int i = 0; i < studentCount; i++) {
                    std::cout << *students[i] << '\n';
                }
            }
        }
        else if (choice == 4) {
            int group{};
            std::cout << "Enter group number: ";
            std::cin >> group;

            double avg = StudentAfterFirstSession::calculateGroupAverageAfterFirstSession((const Student**)students, studentCount, group);
            std::cout << "Average grade for group " << group << " after first session: " << avg << '\n';
        }
        else if (choice == 5) {
            int group{};
            std::cout << "Enter group number: ";
            std::cin >> group;

            double avg = StudentAfterSecondSession::calculateGroupAverageAfterSecondSession((const Student**)students, studentCount, group);
            std::cout << "Average grade for group " << group << " after second session: " << avg << '\n';
        }
        else if (choice == 6) {
            std::cout << "End";
        }
        else {
            std::cout << "Invalid choice! Please try again\n";
        }

    } while (choice != 6);

    for (int i = 0; i < studentCount; i++) {
        delete students[i];
    }

    return 0;
}