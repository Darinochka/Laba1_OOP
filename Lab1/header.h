#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


class CommandsMoving {
public:
	int x, y;                               // x and y coordinate
	int current_time = 0;                   // measured in minutes from the beginning of the moving 
	int speed = 0;

	CommandsMoving();

	CommandsMoving(const int& orig_x, const int& orig_y, const int& new_speed);

	CommandsMoving(const CommandsMoving& commands);

	~CommandsMoving();

	std::vector<int> set_speed(const int& new_time, const int& new_speed);

	std::vector<int> set_radius(const int& new_time, const int& new_radius);

	std::vector<int> get_coord() const;

	int get_speed() const;

	bool operator==(const CommandsMoving& other) const;

	bool operator!=(const CommandsMoving& other) const;

	friend ostream& operator<<(ostream& stream, const CommandsMoving& commands);
};

class Queue {
private:
	class Node {
	public:
		Node* next;
		CommandsMoving data;

		Node();

		Node(CommandsMoving data_new = CommandsMoving(), Node* next_new = nullptr);
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

		CommandsMoving& operator*() const;

		CommandsMoving* operator->() const;

		void operator++(int);

		bool operator==(const Iterator& other);

		bool operator!=(const Iterator& other);

		int get_size() const;

	};

	Queue();

	Queue(const Queue& queue);

	~Queue();

	void clear();

	void enqueue(const CommandsMoving& data);

	Iterator begin() const;

	Iterator end() const;

	CommandsMoving dequeue();

	void load_file(ifstream& stream);

	void save_file(ofstream& stream) const;

	int get_size() const;

	bool operator==(const Queue& other) const;

	bool operator!=(const Queue& other) const;

};

ostream& operator<<(ostream& stream, const CommandsMoving& commands);

ostream& operator<<(ostream& stream, Queue::Iterator iter);

#endif
