#define _CRT_SECURE_NO_WARNINGS
#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <iostream>
#include "Person.h"

class Professor : public Person {
private:
    char* department;
public:
    Professor(const char* = nullptr, const char* = nullptr);
    Professor(const Professor&);
    Professor(Professor&&) noexcept;
    Professor& operator=(const Professor&);
    Professor& operator=(Professor&&) noexcept;
    ~Professor() override;

    void setDepartment(const char*);
    const char* getDepartment() const;

    const char* getType() const override;

    void print() const override;
};

#endif


