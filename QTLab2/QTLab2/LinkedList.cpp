#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP

#include "LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>


using namespace std;

template<class K>
Node<K>::Node(K key, int value, Node* prev, Node* next) {
    this->key = key;
    this->value = value;
    this->prev = prev;
    this->next = next;
};

template <class K>
LinkedList<K>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
};

template<class K>
LinkedList<K>::LinkedList(const LinkedList& lin_list) {
    Node<K>* curr = lin_list.head;

    if (curr != nullptr) {
        while (curr->next != nullptr) {
            curr = curr->next;
            push_back(curr->key, curr->value);
        }
    }
}

template<class K>
LinkedList<K>::~LinkedList() {
    clear();
}

template<class K>
void LinkedList<K>::clear() {
    while (size != 0) {
        Node<K>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class K>
bool LinkedList<K>::is_empty() const {
    return (head == nullptr);
}

template<class K>
void LinkedList<K>::push_back(const K& key, const int& value) {
    if (tail == nullptr) {
        tail = new Node<K>(key, value);
        head = new Node<K>(K(), int(), nullptr, tail);
        tail->prev = head;
    }
    else {
        tail->next = new Node<K>(key, value);
        tail->next->prev = tail;
        tail = tail->next;
    }
    size++;
}

template<class K>
bool LinkedList<K>::delete_by_key(const K& key) {
    Node<K>* curr = head->next;
    bool del_suc = false;

    while (curr != nullptr && not del_suc) {
        if (curr->key == key) {
            curr->prev->next = curr->next;
            if (curr->next != nullptr) {
                curr->next->prev = curr->prev;
            }
            else {
                tail = curr->prev;
            }
            del_suc = true;
            size--;
        }
        curr = curr->next;
    }
    return del_suc;
}

template<class K>
bool LinkedList<K>::operator==(const LinkedList<K>& rs) const {
    Node<K>* curr = head;
    Node<K>* rcurr = rs.head;

    if (curr == nullptr and rcurr == nullptr) {
        return true;
    }

    while (curr->next != nullptr and rcurr->next != nullptr) {
        curr = curr->next;
        rcurr = rcurr->next;
        if (curr->key != rcurr->key || curr->value != rcurr->value) {
            return false;
        }
    }
    return true;
}

template<class K>
bool LinkedList<K>::operator!=(const LinkedList<K>& rs) const {
    return not (*this == rs);
}

template<class K>
int LinkedList<K>::find_value_by_key(const K& key) const {
    Node<K>* curr = head->next;

    while (curr != nullptr) {
        if (curr->key == key) {
            return curr->value;
        }
        curr = curr->next;
    }
    return 0;
}

template<class K>
bool LinkedList<K>::change_value(const K& key, const int& value) {
    Node<K>* current_node = head->next;

    while (current_node != nullptr) {
        if (current_node->key == key) {
            current_node->value = value;
            return true;
        }
        current_node = current_node->next;
    }
    return false;
}

template<class K>
void LinkedList<K>::save_file(ofstream& stream) const {
    Node<K>* current_node = head->next;

    while (current_node != nullptr) {
        stream << current_node->key << " " << current_node->value << endl;
        current_node = current_node->next;
    }
}

#endif // LINKEDLIST_CPP
