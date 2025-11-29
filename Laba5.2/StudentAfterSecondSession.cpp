#include "StudentAfterSecondSession.h"

StudentAfterSecondSession::StudentAfterSecondSession(const std::string& studentName, int studentCourse, int studentGroup,
    int recordBookNumber, const int firstSessionGrades[4], const int secondSessionGrades[5])
    : StudentAfterFirstSession(studentName, studentCourse, studentGroup, recordBookNumber, firstSessionGrades) {
    for (int i = 0; i < 5; ++i) {
        if (secondSessionGrades[i] < 1 || secondSessionGrades[i] > 10) {
            throw std::invalid_argument("Grade must be between 1 and 10");
        }
        grades2[i] = secondSessionGrades[i];
    }
}

StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession& other) : StudentAfterFirstSession(other) {
    for (int i = 0; i < 5; ++i) {
        grades2[i] = other.grades2[i];
    }
}

int StudentAfterSecondSession::getGrade2(int index) const {
    if (index < 0 || index >= 5) {
        throw std::out_of_range("Invalid grade index");
    }
    return grades2[index];
}

void StudentAfterSecondSession::setGrade2(int index, int value) {
    if (index < 0 || index >= 5) {
        throw std::out_of_range("Invalid grade index");
    }
    if (value < 1 || value > 10) {
        throw std::invalid_argument("Grade must be between 1 and 10");
    }
    grades2[index] = value;
}

double StudentAfterSecondSession::getAverageGrade() const {
    double sum = 0.0;
    for (int i = 0; i < 4; ++i) {
        sum += grades[i]; 
    }
    for (int i = 0; i < 5; ++i) {
        sum += grades2[i];
    }
    return sum / 9.0; 
}

double StudentAfterSecondSession::calculateGroupAverageAfterSecondSession(const Student** students, int count, int targetGroup) {
    double sum = 0.0;
    int studentCount{};

    for (int i = 0; i < count; ++i) {
        if (students[i]->getGroup() == targetGroup) {
            const StudentAfterSecondSession* secondSessionStudent = dynamic_cast<const StudentAfterSecondSession*>(students[i]);
            if (secondSessionStudent) {
                sum += secondSessionStudent->getAverageGrade();
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

void StudentAfterSecondSession::printGrades(std::ostream& out) const {
    out << ", First Session Grades: ";
    for (int i = 0; i < 4; ++i) {
        out << grades[i];
        if (i < 3) out << ", ";
    }
    out << ", Second Session Grades: ";
    for (int i = 0; i < 5; ++i) {
        out << grades2[i];
        if (i < 4) out << ", ";
    }
    out << ", Year Average: " << getAverageGrade();
}

std::ostream& operator<<(std::ostream& out, const StudentAfterSecondSession& s) {
    out << static_cast<const StudentAfterFirstSession&>(s);
    s.printGrades(out);
    return out;
}