#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"

Student::Student(const char* name, int courseNum, int groupNum) : Person(name), course(courseNum), group(groupNum) {}

Student::Student(const Student& other) : Person(other), course(other.course), group(other.group) {}

Student::Student(Student&& other) noexcept : Person(other), course(other.course), group(other.group) {
	other.course = 0;
	other.group = 0;
}

Student& Student::operator=(const Student& other) {
	if (this != &other) {
		Person::operator=(other);
		course = other.course;
		group = other.group;
	}
	return *this;
}

Student& Student::operator=(Student&& other) noexcept {
	if (this != &other) {
		Person::operator=(other);
		course = other.course;
		group = other.group;
		other.course = 0;
		other.group = 0;
	}
	return *this;
}

Student::~Student() {}

void Student::setCourse(int courseNum) {
	course = courseNum;
}

int Student::getCourse() const {
	return course;
}

void Student::setGroup(int groupNum) {
	group = groupNum;
}

int Student::getGroup() const {
	return group;
}

void Student::print() const {
	Person::print();
	std::cout << "Course: " << course << "\nGroup: " << group << '\n';
}

const char* Student::getType() const {
	return "Student";
}