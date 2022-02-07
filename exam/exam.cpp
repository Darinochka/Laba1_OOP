#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class Student {
public:
    std::string fio;
    int studVar;
    int subGroup;

    Student() {
        fio = "";
        studVar = 0;
        subGroup = 0;
    }

    Student(const std::string& fio_new, const int& stud_var_new, const int& sub_group_new) {
        fio = fio_new;
        studVar = stud_var_new;
        subGroup = sub_group_new;
    }

    Student(const Student& student) {
        fio = student.fio;
        studVar = student.studVar;
        subGroup = student.subGroup;
    }
};

class Group {
public:
    std::string name;
    Student* students;
    int capacity;
    int size;

    Group() {
        name = "";
        size = 0;
        capacity = 0;
        students = nullptr;
    };

    Group(const std::string& name_new) {
        name = name_new;
        size = 0;
        capacity = 0;
        students = nullptr;
    }

    Group(const Group& group) {
        students = new Student[group.capacity];
        capacity = group.capacity;
        size = group.size;
        name = group.name;
        copyGroup(students, group.students, capacity);
    }

    void addStudent(const Student& student) {
        if (capacity >= size && capacity > 0) {
            Student* temp = new Student[capacity*2];
            copyGroup(temp, students, capacity);

            delete students;
            students = temp;
            capacity *= 2;

            students[size] = student;

        }
        else if (size == 0) {
            students = new Student[1];
            students[0] = student;
        }

        size++;
    }

    Student* getStudent(const std::string& fio_s) {
        for (int i = 0; i < size; i++) {
            if (students[i].fio.find(fio_s) != std::string::npos) {
                return &students[i];
            }
        }
        return nullptr;
    }

private:
    void copyGroup(Student* students_1, Student* students_2, int size) {
        for (int i = 0; i < size; i++) {
            students_1[i] = students_2[i];
        }
    }
};

class Groups {
private:
    class Node {
    public:
        Node* next;
        Group data;

        Node(const Group& group) {
            data = group;
        }

        ~Node(void) = default;

        Node(Group group, Node* next) : data(group), next(next) {}
    };
public:
    int size;
    Node* tail = nullptr;
    Node* head = nullptr;

    Groups(void) = default;

    ~Groups(void) = default;

    void addGroup(const Group& data) {
        if (head == nullptr) {
            head = new Node(data);
            tail = head;
        }
        else {
            tail->next = new Node(data);
            tail = tail->next;
        }
        size++;
    };

    Group* getGroup(const std::string& name_s) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data.name.find(name_s) != std::string::npos) {
                return &curr->data;
            }
            curr = curr->next;
        }
        return nullptr;
    };

    void loadList(const std::string& fname) {
        std::ifstream input(fname);
        if (input.is_open()) {
            std::string row;
            while (input >> row) {

                std::string row_data[5];
                std::string word;
                int i = 0;

                while (getline(row, word, ',')) {
                    row_data[i] = word;
                    i++;
                }

                Student temp_st(row_data[2], std::stoi(row_data[1]), std::stoi(row_data[3]));
                Group temp(row_data[0]);
                temp.addStudent(temp_st);

            }
        }
    }

};