#include "header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Queue::Iterator::Iterator(){
    i = nullptr;
};

Queue::Iterator::Iterator(Node* n) {
    i = n;
};

Queue::Iterator::Iterator(const Iterator& other) {
    i = other.i;
};

CommandsMoving& Queue::Iterator::operator*() const {
    return i->data;
};

CommandsMoving* Queue::Iterator::operator->() const {
    return &i->data;
};

Queue::Iterator& Queue::Iterator::operator++() {
    i = i->next;
    return *this;
}

Queue::Iterator Queue::Iterator::operator++(int) {
    Node* n = i;
    ++i;
    return n;
}

Queue::Iterator& Queue::Iterator::operator--() {
    i--;
    return *this;
}

Queue::Iterator Queue::Iterator::operator--(int) {
    Node* n = i;
    ++i;
    return n;
}

bool Queue::Iterator::operator==(const Iterator& other){
    Node* curr = i;
    Node* rcurr = other.i;

    while (curr->next != nullptr) {
        if (curr->data != rcurr->data) {
            return false;
        }
        curr = curr->next;
        rcurr = rcurr->next;
    }
    return true;
}

bool Queue::Iterator::operator!=(const Iterator& other) {
    return !(*this == other);
}

bool Queue::Iterator::operator<(const Iterator& other) const {
    return i < other.i;
}

bool Queue::Iterator::operator<=(const Iterator& other) const {
    return i <= other.i;
}

bool Queue::Iterator::operator>(const Iterator& other) const {
    return i > other.i;
}

bool Queue::Iterator::operator>=(const Iterator& other) const {
    return i >= other.i;
}
