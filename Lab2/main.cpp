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

    // проверока размера таблицы по умолчанию
    assert(table.get_size() == 0);
    cout << "Проверка размера таблицы по умолчанию прошла успешно" << endl;

    // проверка очищения коллекции
    ifstream input("input.txt");
    table.load_file(input);
    table.clear();

    assert(table == table1);
    cout << "Проверка очищения коллекции прошла успешно" << endl;

    // проверка сохранения
    ifstream input1("input.txt");
    ofstream output("output.txt");

    table.load_file(input1);
    table.save_file(output);

    ifstream input2("output.txt");
    table1.load_file(input2);

    assert(table1 == table);
    cout << "Проверка сохранения прошла успешно" << endl;

    // При добавлении нового ключа K размер коллекции увеличивается на единицу
    HashTable<Student> table2(table);

    Student darisha("Darina");
    table2.insert(darisha, 5);

    assert(table.get_size() + 1 == table2.get_size());
    assert(table2 != table);
    cout << "Проверка размера коллекции при добавлении нового ключа прошла успешно" << endl;

    // При добавлении имеющегося ключа K размер остаётся прежним, а значение V увеличивается на единицу
    int old_value = table2[darisha];

    table2 << darisha;

    assert(old_value + 1 == table2[darisha]);
    cout << "Проверка добавления имеющегося ключа прошла успешно" << endl;

    // При удалении существующего ключа K размер коллекции уменьшается на единицу, 
    // а при удалении отсутствующего ключа K размер не изменяется

    int old_size = table2.get_size();

    table2.erase(darisha);
    assert(old_size - 1 == table2.get_size());
    cout << "Размер уменьшился успешно при удалении" << endl;

    int old_size2 = table2.get_size();

    Student alena("Alena");
    table2.erase(alena);
    assert(old_size2 == table2.get_size());
    cout << "Размер успешно не изменился при удалении несуществующего ключа" << endl;
}

