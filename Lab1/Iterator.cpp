#include "header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ostream& operator<<(ostream& stream, Queue::Iterator iter) {
    cout << iter.numerator;
    return stream;
}

Queue::Iterator::Iterator(){
    i = nullptr;
    numerator = 0;
};

Queue::Iterator::Iterator(Node* n) {
    i = n;
    numerator = 0;
};

Queue::Iterator::Iterator(const Iterator& other) {
    i = other.i;
    numerator = other.numerator;
};

CommandsMoving& Queue::Iterator::operator*() const {
    return i->data;
};

CommandsMoving* Queue::Iterator::operator->() const {
    return &i->data;
};

void Queue::Iterator::operator++(int) {
    i = i->next;
    numerator++;
}

bool Queue::Iterator::operator==(const Iterator& other){
    Node* curr = i;
    Node* rcurr = other.i;
    
    if ((curr != nullptr && rcurr == nullptr) ||
        (curr == nullptr && rcurr != nullptr)) {
        return false;
    }
    else if (curr == nullptr && rcurr == nullptr) {
        return true;
    }

    if (get_size() == other.get_size()) {
        while (curr->next != nullptr && rcurr->next != nullptr) {
            if (curr->data != rcurr->data) {
                return false;
            }
            curr = curr->next;
            rcurr = rcurr->next;
        }
        return true;
    }
    return false;
}

bool Queue::Iterator::operator!=(const Iterator& other) {
    return !(*this == other);
}

int Queue::Iterator::get_size() const {
    Node* curr = i;
    int size = 0;

    while (curr->next != nullptr) {
        size++;
        curr = curr->next;
    }

    return size;
}
