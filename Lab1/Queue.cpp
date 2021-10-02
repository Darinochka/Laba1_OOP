#include "header.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


Queue::Node::Node(CommandsMoving data_new, Node* next_new) {
    data = data_new;
    next = next_new;
}

Queue::Node::Node() {
    data = CommandsMoving();
    next = nullptr;
};

Queue::Queue() {
    size = 0;
    head = nullptr;
    tail = nullptr;
};

Queue::Queue(const Queue& queue) {
    size = queue.size;
    head = queue.head;
    tail = queue.tail;
}

Queue::~Queue() {
    clear();
};

void Queue::clear() {
    while (size != 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    head = nullptr;
    tail = nullptr;
}

void Queue::enqueue(const CommandsMoving& data) {           // adds to tail of queue
    if (tail == nullptr) {
        tail = new Node(data);
        head = new Node(CommandsMoving(), tail);
    }
    else {
        tail->next = new Node(data);
        tail = tail->next;
    }
    size++;
};

Queue::Iterator Queue::begin() const {
    return Iterator(head->next);
}

Queue::Iterator Queue::end() const {
    return Iterator(tail->next);
}

CommandsMoving Queue::dequeue() {                          // delete from queue the first element
    Node* current = head->next;
    CommandsMoving data = head->data;

    delete head;
    head = current;
    head->data = CommandsMoving();
    size--;

    return data;
}

void Queue::load_file(ifstream& stream) {
    int x, y, speed;

    while (stream >> x >> y >> speed) {
        enqueue(CommandsMoving(x, y, speed));     
    }
}

void Queue::save_file(ofstream& stream) const {
    Node* current = head->next;

    while (current->next != nullptr) {
        int x = current->data.get_coord()[0];
        int y = current->data.get_coord()[1];

        stream << x << y << current->data.get_speed() << endl;
    }
}
    
int Queue::get_size() const {
    return size;
};

bool Queue::operator==(const Queue& other) const{
    if (get_size() == other.get_size() &&
        begin() == other.begin()) {
        return true;
    }
    return false;
}

bool Queue::operator!=(const Queue& other) const{
    if (get_size() != other.get_size() ||
        begin() != other.begin()) {
        return true;
    }
    return false;
}

void Queue::print() const{
    Iterator iter;

    for (iter = begin(); iter!=end(); iter++) {
        cout << *iter << " ";
    }
}
