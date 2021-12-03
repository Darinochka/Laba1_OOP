#include "HashTable.h"
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>


using namespace std;


template <class K>
HashTable<K>::HashTable() {
    capacity = 20;
    size = 0;
    array.resize(capacity);
};

template <class K>
HashTable<K>::HashTable(const int& capacity) {
    this->capacity = capacity;
    size = 0;
    array.resize(capacity);
};

template <class K>
HashTable<K>::HashTable(const HashTable& ht) {
    capacity = ht.get_capacity();
    size = ht.get_size();

    copy(ht.array.begin(), ht.array.end(), back_inserter(array));
}

template <class K>
HashTable<K>::~HashTable() {
    clear();
}

template <class K>
void HashTable<K>::clear() {
    for (int i = 0; i != capacity; i++) {
        if (not array[i].is_empty()) {
            array[i].clear();
        }
    }
    capacity = 20;
    size = 0;
    vector<LinkedList<K>> array;
    array.resize(capacity);
}

template <class K>
int HashTable<K>::get_size() const{
    return size;
}

template <class K>
int HashTable<K>::get_capacity() const {
    return capacity;
}

template <class K>
void HashTable<K>::load_file(ifstream& stream) {
    K key;
    int value;

    // предполагаем, что оператор >> определен для объекта K
    while (stream >> key >> value) {
        insert(key, value);
    }
}

template <class K>
void HashTable<K>::save_file(ofstream& stream) const {
    for (int i = 0; i != capacity; i++) {
        if (not array[i].is_empty()) {
            array[i].save_file(stream);
        }
    }
}

template <class K>
bool HashTable<K>::operator==(const HashTable& ht) const {
    if (get_size() == ht.get_size() &&
        get_capacity() == ht.get_capacity()) {

        for (int i = 0; i < size; i++) {
            if (array[i] != ht.array[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

template<class K>
bool HashTable<K>::operator!=(const HashTable& ht) const {
    if (get_size() == ht.get_size() &&
        get_capacity() == ht.get_capacity()) {

        for (int i = 0; i < size; i++) {
            if (array[i] != ht.array[i]) {
                return true;
            }
        }
        return false;
    }
    return true;
}
template<class K>
long HashTable<K>::hash_f(const string& str) const{
    return std::hash<string>{}(str) % capacity;
}
template <class K>
void HashTable<K>::operator<<(const K& key) {
    int hash_index = hash_f(key.name);

    if (array[hash_index].is_empty()) {
        insert(key, 1);
    } else {
        int value = array[hash_index].find_value_by_key(key);
        insert(key, value+1);
    }
}

template <class K>
void HashTable<K>::erase(const K& key) {
    int hash_index = hash_f(key.name);

    if (not array[hash_index].is_empty()) {
        bool del_suc = array[hash_index].delete_by_key(key);
        if (del_suc) {
            size--;
        }
    }

}

template <class K>
int HashTable<K>::operator[](const K& key) const{
    int hash_index = hash_f(key.name);

    if (not array[hash_index].is_empty()) {
        return array[hash_index].find_value_by_key(key);
    }
    return 1;
}

template <class K>
vector<K> HashTable<K>::get_max_values() const {
    return max_keys;
}

template <class K>
void HashTable<K>::compare_max_values(const K& key, const int& value) {

    if ((size == 1) ||
            (max_values.size() > 0 && max_values[0] < value)) {
        K old_first_key = max_keys[0];
        int old_first_val = max_values[0];
        max_keys[0] = key;
        max_values[0] = value;
        
        K old_sec_key = max_keys[1];
        int old_sec_val = max_values[1];
        max_keys[1] = old_first_key;
        max_values[1] = old_first_val;

        max_keys[2] = old_sec_key;
        max_values[2] = old_sec_val;
    } else if ((size == 2) ||
               (max_values.size() > 1 && max_values[1] < value)) {
        K old_sec_key = max_keys[1];
        int old_sec_val = max_values[1];

        max_keys[1] = key;
        max_values[1] = value;

        max_keys[2] = old_sec_key;
        max_values[2] = old_sec_val;
    } else if ((size == 3) ||
               (max_values.size() > 2 && max_values[2] < value)) {
        max_keys[2] = key;
        max_values[2] = value;
    }
}

template <class K>
void HashTable<K>::increase_capacity() {
    for (int i = 0; i != capacity; i++) {
        LinkedList<K> temp;
        array.push_back(temp);
    }
    capacity *= 2;
}

template <class K>
void HashTable<K>::insert(const K& key, const int& value) {
    array.resize(capacity);
    if (capacity <= size * 2) {
        increase_capacity();
    }

    int hash_index = hash_f(key.name);
    bool exist = false; // существует ли ключ уже

    if (not array[hash_index].is_empty()) {
        exist = array[hash_index].change_value(key, value);
    }

    if (not exist) {
        array[hash_index].push_back(key, value);
    }

    size++;
    compare_max_values(key, value);
};
