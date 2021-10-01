#include "header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Queue::Iterator::Iterator(){

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
    i++;
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

Queue::Iterator& Queue::Iterator::operator--() {
    Node* n = i;
    ++i;
    return *this;
}

bool Queue::Iterator::operator==(const Iterator& other) const {
    return i == other.i;
}

bool Queue::Iterator::operator!=(const Iterator& other) const {
    return i != other.i;
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