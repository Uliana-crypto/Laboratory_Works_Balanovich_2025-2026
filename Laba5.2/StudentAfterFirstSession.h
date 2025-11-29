#ifndef StudentAfterFirstSession_H
#define StudentAfterFirstSession_H

#include <iostream>
#include <string>
#include "Student.h"

class StudentAfterFirstSession : public Student {
protected:
    int grades[4];

    void printGrades(std::ostream&) const override;
public:
    StudentAfterFirstSession() = delete;
    StudentAfterFirstSession(const std::string&, int, int, int, const int[4]);
    StudentAfterFirstSession(const StudentAfterFirstSession&);

    int getGrade(int) const;
    void setGrade(int, int);

    double getAverageGrade() const override;

    static double calculateGroupAverageAfterFirstSession(const Student**, int, int);
    friend std::ostream& operator<<(std::ostream&, const StudentAfterFirstSession&);
};

#endif
