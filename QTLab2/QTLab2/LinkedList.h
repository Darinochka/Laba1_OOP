#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


template<class K>
class Node {
public:
    K key;
    int value;
    Node* next;
    Node* prev;

    Node(K key = K(), int value = 0, Node* prev = nullptr, Node* next = nullptr);
};

template <class K>
class LinkedList {
private:
    Node<K>* head = nullptr;
    Node<K>* tail = nullptr;
    int size = 0;

public:
    LinkedList();

    LinkedList(const LinkedList& lin_list);

    ~LinkedList();

    void clear();

    void push_back(const K& key, const int& value);

    bool delete_by_key(const K& key);

    bool is_empty() const;

    bool operator==(const LinkedList& rs) const;

    bool operator!=(const LinkedList& rs) const;

    int find_value_by_key(const K& key) const;

    bool change_value(const K& key, const int& value); // вернет true если найдет ключ key и поменяет на новое value

    void save_file(std::ofstream& stream) const;
};

#endif // LINKEDLIST_H
