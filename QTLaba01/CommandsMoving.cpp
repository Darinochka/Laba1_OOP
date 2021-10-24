#include "CommandsMoving.h"
#include <vector>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& stream, const MoveCommand& command) {
    cout << command.get_time();
    if (command.is_rotation()) {
        cout << " rotation " << command.get_radius();
    }
    else {
        cout << " speed " << command.get_speed();
    }
    return stream;
}

MoveCommand::MoveCommand() {                                           // default constructor
    current_time = 0;
    speed = 0;
}

MoveCommand::MoveCommand(const int& new_time, const int& new_speed) {      // initialization constructor
    current_time = new_time;
    speed = new_speed;
}

MoveCommand::MoveCommand(const MoveCommand& commands) {            // copy  constructor
    current_time = commands.current_time;
    speed = commands.speed;
}

MoveCommand::~MoveCommand() {
}

int MoveCommand::get_speed() const {
    return speed;
}

int MoveCommand::get_radius() const {
    return 0;
}

int MoveCommand::get_time() const {
    return current_time;
}

bool MoveCommand::is_rotation() const{
    return false;
}

bool MoveCommand::operator==(const MoveCommand& other) const{
    return (get_time() == other.get_time() &&
        get_speed() == other.get_speed() &&
        get_radius() == other.get_radius());
}

bool MoveCommand::operator!=(const MoveCommand& other) const{
    return (get_time() != other.get_time() ||
        get_speed() != other.get_speed() ||
        get_radius() != other.get_radius());
}

Rotation::Rotation() : MoveCommand() {
    radius = 1;
}

Rotation::Rotation(const int& time, const int& new_radius) : MoveCommand(time, 0) {
    radius = new_radius;
}

Rotation::Rotation(const Rotation& command) : MoveCommand(command.current_time, 0) {
    radius = command.radius;
}

int Rotation::get_radius() const {
    return radius;
}

bool Rotation::is_rotation() const {
    return true;
}
