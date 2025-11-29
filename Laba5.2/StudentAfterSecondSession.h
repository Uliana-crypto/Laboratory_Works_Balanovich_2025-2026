#ifndef StudentAfterSecondSession_H
#define StudentAfterSecondSession_H

#include <iostream>
#include <string>
#include "StudentAfterFirstSession.h"

class StudentAfterSecondSession : public StudentAfterFirstSession {
protected:
    int grades2[5];
    void printGrades(std::ostream&) const override;
public:
    StudentAfterSecondSession() = delete;
    StudentAfterSecondSession(const std::string&, int, int, int, const int[4], const int[5]);
    StudentAfterSecondSession(const StudentAfterSecondSession&);

    int getGrade2(int) const;
    void setGrade2(int, int);

    double getAverageGrade() const override;
    static double calculateGroupAverageAfterSecondSession(const Student**, int, int);

    friend std::ostream& operator<<(std::ostream&, const StudentAfterSecondSession&);
};

#endif
