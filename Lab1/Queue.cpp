#include "header.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Queue::Iterator::Iterator() : i(0) {

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


Queue::Node::Node(CommandsMoving data_new = CommandsMoving(), Node* next_new = nullptr) {
    data = data_new;
    next = next_new;
}

Queue::Node::Node() {

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

void Queue::enqueue(const CommandsMoving& data) {          // adds to tail of queue
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

Queue::Node* Queue:: get_head() const {
        return head;
    }

Queue::Node* Queue:: get_tail() const {
        return tail;
    }

CommandsMoving Queue:: dequeue() {                            // delete from queue the last element
    Node* current = head->next;
    CommandsMoving data = head->data;

    delete head;
    head = current;
    head->data = CommandsMoving();
    size--;

    return data;
}

void Queue:: load_file(ifstream& stream) {
    Node* current = tail;
    int x, y, speed;

    while (stream >> x >> y >> speed) {
        this->enqueue(CommandsMoving(x, y, speed));     
    }
}

void Queue:: save_file(ostream& stream) const {
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
