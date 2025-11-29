#include "StudentAfterFirstSession.h"

StudentAfterFirstSession::StudentAfterFirstSession(const std::string& studentName, int studentCourse, int studentGroup,
    int recordBookNumber, const int firstSessionGrades[4]) : Student(studentName, studentCourse, studentGroup, recordBookNumber) {
    for (int i = 0; i < 4; ++i) {
        if (firstSessionGrades[i] < 1 || firstSessionGrades[i] > 10) {
            throw std::invalid_argument("Grade must be between 1 and 10");
        }
        grades[i] = firstSessionGrades[i];
    }
}

StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& other) : Student(other) {
    for (int i = 0; i < 4; ++i) {
        grades[i] = other.grades[i];
    }
}

int StudentAfterFirstSession::getGrade(int index) const {
    if (index < 0 || index >= 4) {
        throw std::out_of_range("Invalid grade index");
    }
    return grades[index];
}

void StudentAfterFirstSession::setGrade(int index, int value) {
    if (index < 0 || index >= 4) {
        throw std::out_of_range("Invalid grade index");
    }
    if (value < 1 || value > 10) {
        throw std::invalid_argument("Grade must be between 1 and 10");
    }
    grades[index] = value;
}

double StudentAfterFirstSession::getAverageGrade() const {
    double sum = 0.0;
    for (int i = 0; i < 4; ++i) {
        sum += grades[i];
    }
    return sum / 4.0;
}

double StudentAfterFirstSession::calculateGroupAverageAfterFirstSession(const Student** students, int count, int targetGroup) {
    double sum = 0.0;
    int studentCount{};

    for (int i = 0; i < count; ++i) {
        if (students[i]->getGroup() == targetGroup) {
            const StudentAfterFirstSession* firstSessionStudent = dynamic_cast<const StudentAfterFirstSession*>(students[i]);
            if (firstSessionStudent) {
                sum += firstSessionStudent->getAverageGrade();
                studentCount++;
            }
        }
    }
    if (studentCount > 0) {
        return sum / studentCount;
    }
    else {
        return 0.0;
    }
}

void StudentAfterFirstSession::printGrades(std::ostream& out) const {
    out << ", First Session Grades: ";
    for (int i = 0; i < 4; ++i) {
        out << grades[i];
        if (i < 3) out << ", ";
    }
    out << ", Average: " << getAverageGrade();
}

std::ostream& operator<<(std::ostream& out, const StudentAfterFirstSession& s) {
    out << static_cast<const Student&>(s);
    s.printGrades(out);
    return out;
}