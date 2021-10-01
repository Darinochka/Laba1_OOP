#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>
#include <vector>


class CommandsMoving {
private:
    int x, y;                               // x and y coordinate
    int current_time = 0;                   // measured in minutes from the beginning of the moving 
    int speed = 0;

public:
    CommandsMoving();

    CommandsMoving(const int& orig_x, const int& orig_y, const int& new_speed);

    CommandsMoving(const CommandsMoving& commands);

    ~CommandsMoving();

    std::vector<int> set_speed(const int& new_time, const int& new_speed);

    std::vector<int> set_radius(const int& new_time, const int& new_radius);

    std::vector<int> get_coord() const;

    int get_speed() const;
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

    class Iterator {
    public: 
        Node* i;

        inline Iterator();

        inline Iterator(Node* other);

        inline Iterator(const Iterator& other);

        inline CommandsMoving &operator*() const;
        
        inline CommandsMoving *operator->() const;

        inline Iterator& operator++();

        inline Iterator operator++(int);

        inline Iterator& operator--();

        inline Iterator operator--(int);

        inline bool operator==(const Iterator& other) const;

        inline bool operator!=(const Iterator& other) const;

        inline bool operator<(const Iterator& other) const;
        
        inline bool operator<=(const Iterator& other) const;
         
        inline bool operator>(const Iterator& other) const;
        
        inline bool operator>=(const Iterator& other) const;
    };

    int size;
    Node* tail; // tail -> null
    Node* head; // head -> next

public:
    Queue();

    Queue(const Queue& queue);

    ~Queue();

    void clear();

    void enqueue(const CommandsMoving& data);

    Iterator begin() const;

    Iterator end() const;

    CommandsMoving dequeue();

    void load_file(ifstream& stream);

    void save_file(ostream& stream) const;

    int get_size() const;

};


#endif
