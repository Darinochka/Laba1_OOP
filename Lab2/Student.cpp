#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

Student::Student() {
    name = "";
}

Student::Student(const string& n_name) {
    name = n_name;
}

Student::Student(const Student& student) {
    name = student.name;
}

Student::~Student() {

}

string Student::get_name() const {
    return name;
}

bool Student::operator==(const Student& student) {
    return (name == student.name);
}

bool Student::operator!=(const Student& student) {
    return (name != student.name);
}

std::istream& operator>>(std::istream& stream, Student& st) {
    stream >> st.name;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Student& st) {
    stream << st.name;
    return stream;
}
