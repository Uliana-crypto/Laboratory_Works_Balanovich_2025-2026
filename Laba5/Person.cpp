#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"

Person::Person(const char* name) {
	if (name) {
		fullName = new char[strlen(name) + 1];
		strcpy(fullName, name);
	}
	else {
		fullName = nullptr;
	}
}

Person::Person(const Person& other) {
	if (other.fullName) {
		fullName = new char[strlen(other.fullName) + 1];
		strcpy(fullName, other.fullName);
	}
	else
	{
		fullName = nullptr;
	}
}

Person::Person(Person&& other) noexcept : fullName(other.fullName) {
	other.fullName = nullptr;
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		delete[] fullName;
		if (other.fullName) {
			fullName = new char[strlen(other.fullName) + 1];
			strcpy(fullName, other.fullName);
		}
		else {
			fullName = nullptr;
		}
	}
	return *this;
}

Person& Person::operator=(Person&& other) noexcept {
	if (this != &other) {
		delete[] fullName;
		fullName = other.fullName;
		other.fullName = nullptr;
	}
	return *this;
}

Person::~Person() {
	delete[] fullName;
}

void Person::setFullName(const char* name) {
	if (name) {
		fullName = new char[strlen(name) + 1];
		strcpy(fullName, name);
	}
	else {
		fullName = nullptr;
	}
}
const char* Person::getFullName() const {
	return fullName;
}

void Person::print() const {
	std::cout << "Full name: ";
	if (fullName) {
		std::cout << fullName;
	}
	else {
		std::cout << "not available";
	}
	std::cout << '\n';
}

bool isDigitsOnly(const std::string& s) {
	if (s.empty()) {
		return false;
	}
	for (char c : s) {
		if (!std::isdigit(static_cast<unsigned char>(c)))
		{
			return false;
		}
	}
	return true;
}