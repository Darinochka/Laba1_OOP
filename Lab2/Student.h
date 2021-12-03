#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>


class Student {
public:
    std::string name;

    Student();

    Student(const std::string& n_name);

    Student(const Student& k);

    ~Student();

    std::string get_name() const;

    bool operator==(const Student& student);

    bool operator!=(const Student& student);
};

std::istream& operator>>(std::istream& stream, Student& st);

std::ostream& operator<<(std::ostream& stream, Student& st);

#endif
