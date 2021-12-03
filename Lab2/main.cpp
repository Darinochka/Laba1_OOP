#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include "HashTable.h"
#include "HashTable.cpp"
#include "Student.h"

using namespace std;

int main() {
    HashTable<Student> table;
    HashTable<Student> table1;

    // ��������� ������� ������� �� ���������
    assert(table.get_size() == 0);
    cout << "�������� ������� ������� �� ��������� ������ �������" << endl;

    // �������� �������� ���������
    ifstream input("input.txt");
    table.load_file(input);
    table.clear();

    assert(table == table1);
    cout << "�������� �������� ��������� ������ �������" << endl;

    // �������� ����������
    ifstream input1("input.txt");
    ofstream output("output.txt");

    table.load_file(input1);
    table.save_file(output);

    ifstream input2("output.txt");
    table1.load_file(input2);

    assert(table1 == table);
    cout << "�������� ���������� ������ �������" << endl;

    // ��� ���������� ������ ����� K ������ ��������� ������������� �� �������
    HashTable<Student> table2(table);

    Student darisha("Darina");
    table2.insert(darisha, 5);

    assert(table.get_size() + 1 == table2.get_size());
    assert(table2 != table);
    cout << "�������� ������� ��������� ��� ���������� ������ ����� ������ �������" << endl;

    // ��� ���������� ���������� ����� K ������ ������� �������, � �������� V ������������� �� �������
    int old_value = table2[darisha];

    table2 << darisha;

    assert(old_value + 1 == table2[darisha]);
    cout << "�������� ���������� ���������� ����� ������ �������" << endl;

    // ��� �������� ������������� ����� K ������ ��������� ����������� �� �������, 
    // � ��� �������� �������������� ����� K ������ �� ����������

    int old_size = table2.get_size();

    table2.erase(darisha);
    assert(old_size - 1 == table2.get_size());
    cout << "������ ���������� ������� ��� ��������" << endl;

    int old_size2 = table2.get_size();

    Student alena("Alena");
    table2.erase(alena);
    assert(old_size2 == table2.get_size());
    cout << "������ ������� �� ��������� ��� �������� ��������������� �����" << endl;
}

