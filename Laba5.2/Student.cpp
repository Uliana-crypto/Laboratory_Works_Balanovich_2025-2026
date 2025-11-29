#include "Student.h"

int Student::nextId = 1;

Student::Student(const std::string& studentName, int studentCourse, int studentGroup, int recordBookNumber) : id(nextId++), 
name(studentName), course(studentCourse), group(studentGroup), recBookNum(recordBookNumber) {}

Student::Student(const Student& other) : id(nextId++), name(other.name), course(other.course),
group(other.group), recBookNum(other.recBookNum) {}

int Student::getId() const 
{
	return id;

}
std::string Student::getName() const
{
	return name; 
}

void Student::setName(const std::string& newName)
{
	name = newName; 
}

int Student::getCourse() const {
	return course;
}

void Student::setCourse(int newCourse) {
	if (newCourse < 1 || newCourse > 6) {
		throw std::invalid_argument("Course must be between 1 and 6");
	}
	course = newCourse;
}

int Student::getGroup() const {
	return group;
}

void Student::setGroup(int newGroup) {
	group = newGroup;
}

int Student::getRecBookNum() const {
	return recBookNum; 
}

std::ostream& operator<<(std::ostream& out, const Student& s)
{
	out << "ID: " << s.id
		<< ", Name: " << s.name
		<< ", Course: " << s.course
		<< ", Group: " << s.group
		<< ", RecordBook: " << s.recBookNum;
	return out;
}

std::istream& operator>>(std::istream& in, Student& s) {
	std::cout << "Enter name: ";
	in >> s.name;
	std::cout << "Enter course: ";
	in >> s.course;
	std::cout << "Enter group: ";
	in >> s.group;
	return in;
}

double Student::getAverageGrade() const {
	return 0.0; 
}