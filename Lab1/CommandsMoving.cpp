#include "header.h"
#include <vector>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& stream, const CommandsMoving& commands) {
    cout << commands.get_coord()[0] << commands.get_coord()[1] << 
        commands.get_speed();
    return stream;
}

CommandsMoving::CommandsMoving() {                                           // default constructor
    x = 0;
    y = 0;
    speed = 0;
}

CommandsMoving::CommandsMoving(const int& orig_x, const int& orig_y, const int& new_speed) {      // initialization constructor
    x = orig_x;
    y = orig_y;
    speed = new_speed;
}

CommandsMoving::CommandsMoving(const CommandsMoving& commands) {            // copy  constructor
    x = commands.x;
    y = commands.y;
    speed = commands.speed;
}

CommandsMoving::~CommandsMoving() {
}

vector<int> CommandsMoving::set_speed(const int& new_time, const int& new_speed) {
    int tempTime = new_time - current_time;
    int s = tempTime * new_speed;
    x = x + s;
    current_time = new_time;
    speed = new_speed;
    return get_coord();
}

vector<int> CommandsMoving::set_radius(const int& new_time, const int& new_radius) {
    int tempTime = new_time - current_time;
    int alpha = (speed / new_radius) * tempTime;
    x = round(new_radius * cos(alpha) + x);
    y = round(new_radius * sin(alpha) + y);
    current_time = new_time;
    return get_coord();
}

vector<int> CommandsMoving::get_coord() const {                             // returns coordinates
    return { x, y };
}

int CommandsMoving::get_speed() const {
    return speed;
}

bool CommandsMoving::operator==(const CommandsMoving& other) const{
    return (get_coord() == other.get_coord() &&
        get_speed() == other.get_speed());
}

bool CommandsMoving::operator!=(const CommandsMoving& other) const{
    return (get_coord() != other.get_coord() &&
        get_speed() != other.get_speed());
}