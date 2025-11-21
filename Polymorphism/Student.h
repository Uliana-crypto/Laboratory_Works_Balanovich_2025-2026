#define _CRT_SECURE_NO_WARNINGS
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Person.h"

class Student : public Person {
private:
    int group;
    int course;
public:
    Student(const char* = nullptr, int = 0, int = 0);
    Student(const Student&);
    Student(Student&&) noexcept;
    Student& operator=(const Student&);
    Student& operator=(Student&&) noexcept;
    ~Student() override;

    void setCourse(int);
    int getCourse() const;
    void setGroup(int);
    int getGroup() const;

    const char* getType() const override;

    void print() const override;
};

#endif

