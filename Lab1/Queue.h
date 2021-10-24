#ifndef QUEUE_H
#define QUEUE_H

#include "CommandsMoving.h"
#include <iostream>
#include <vector>
#include <fstream>


class Queue {
private:
	class Node {
	public:
		Node* next;
		MoveCommand* data;
	};
	
	int size;
	Node* tail; // tail -> null
	Node* head; // head -> next
public:
	class Iterator {
	public:
		Node* i;
		int numerator = 0;
		
		Iterator();

		Iterator(Node* other);

		Iterator(const Iterator& other);

		MoveCommand& operator*() const;

		MoveCommand* operator->() const;

		void operator++(int);

		bool operator==(const Iterator& other);

		bool operator!=(const Iterator& other);

		int get_size() const;

	};

	Queue();

	Queue(const Queue& queue);

	~Queue();

	void clear();

	void enqueue(MoveCommand& data);

	Iterator begin() const;

	Iterator end() const;

	void dequeue();

	void load_file(std::ifstream& stream);

	void save_file(std::ofstream& stream) const;

	int get_size() const;

	std::vector <int> get_coord() const;

	bool operator==(const Queue& other) const;

	bool operator!=(const Queue& other) const;

};

std::ostream& operator<<(std::ostream& stream, Queue::Iterator iter);

#endif
