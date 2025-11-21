#define _CRT_SECURE_NO_WARNINGS
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>

class Person {
protected:
    char* fullName;
public:
    Person(const char* = nullptr);
    Person(const Person&);
    Person(Person&&) noexcept;
    Person& operator=(const Person&);
    Person& operator=(Person&&) noexcept;
    virtual ~Person();

    void setFullName(const char*);
    const char* getFullName() const;

    virtual void print() const;
    virtual const char* getType() const = 0;
};

bool isDigitsOnly(const std::string&);

#endif

