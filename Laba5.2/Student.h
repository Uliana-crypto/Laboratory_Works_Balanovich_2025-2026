#ifndef STUDENT_T
#define STUDENT_T

#include <iostream>
#include <string>

class Student {
protected:
	const int id;
    std::string name;
    int course;             
    int group;           
    const int recBookNum;
    static int nextId;

    virtual void printGrades(std::ostream&) const = 0;
public:
    Student() = delete;
    Student(const std::string&, int, int, int);
    Student(const Student&);
    virtual ~Student() = default;

    int getId() const;
    std::string getName() const;
    void setName(const std::string&);

    int getCourse() const;
    void setCourse(int);

    int getGroup() const;
    void setGroup(int);

    int getRecBookNum() const;

    friend std::ostream& operator<<(std::ostream&, const Student&);
    friend std::istream& operator>>(std::istream&, Student&);

    virtual double getAverageGrade() const;
};

#endif
