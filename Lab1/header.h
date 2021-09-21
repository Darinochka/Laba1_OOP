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

#endif
