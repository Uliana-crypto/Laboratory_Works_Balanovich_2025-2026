#define _CRT_SECURE_NO_WARNINGS
#include "Professor.h"

Professor::Professor(const char* name, const char* depart) : Person(name) {
	if (depart) {
		department = new char[strlen(depart) + 1];
		strcpy(department, depart);
	}
	else {
		department = nullptr;
	}
}

Professor::Professor(const Professor& other) : Person(other) {
	if (other.department) {
		department = new char[strlen(other.department) + 1];
		strcpy(department, other.department);
	}
	else department = nullptr;
}

Professor::Professor(Professor&& other) noexcept : Person(other), department(other.department) {
	other.department = nullptr;
}

Professor& Professor::operator=(const Professor& other) {
	if (this != &other) {
		Person::operator=(other);
		delete[] department;
		if (other.department) {
			department = new char[strlen(other.department) + 1];
			strcpy(department, other.department);
		}
		else {
			department = nullptr;
		}
	}
	return *this;
}

Professor& Professor::operator=(Professor&& other) noexcept {
	if (this != &other) {
		Person::operator=(std::move(other));
		delete[] department;
		department = other.department;
		other.department = nullptr;
	}
	return *this;
}

Professor::~Professor() {
	delete[] department;
}

void Professor::setDepartment(const char* depart) {
	if (depart) {
		department = new char[strlen(depart) + 1];
		strcpy(department, depart);
	}
	else {
		department = nullptr;
	}
}

const char* Professor::getDepartment() const {
	return department;
}

void Professor::print() const {
	Person::print();
	std::cout << "Department: ";
	if (department) {
		std::cout << department;
	}
	else {
		std::cout << "not available";
	}
	std::cout << '\n';
}

const char* Professor::getType() const {
	return "Professor";
}
