#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "LinkedList.cpp"

template <class K>
class HashTable {
private:
    int capacity = 20;
    int size = 0;
    vector<LinkedList<K>> array;
    std::vector<int> max_values = { 0, 0, 0 };
    std::vector<K> max_keys = { K(), K(), K() };
    vector<K> keys;

public:
    HashTable();

    HashTable(const int& capacity);

    HashTable(const HashTable& ht);

    ~HashTable();

    void clear();

    int get_size() const;

    long hash_f(const string& str) const;

    int get_capacity() const;

    void load_file(std::ifstream& stream);

    void save_file(std::ofstream& stream) const;

    void change_max_values();

    int get_value(const K& key) const;

    bool operator==(const HashTable& ht) const;

    bool operator!=(const HashTable& ht) const;

    void operator<<(const K& key);

    void erase(const K& key);

    int operator[](const K& key) const;

    std::vector <K> get_max_values() const;

    void compare_max_values(const K& key, const int& value);

    void increase_capacity();

    void insert(const K& key, const int& value);

    vector<K> get_keys() const;
};

#endif
