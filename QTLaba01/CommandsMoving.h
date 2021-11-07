#ifndef COMMANDS_H
#define COMMANDS_H


#include <iostream>
#include <vector>
#include <fstream>

class MoveCommand {
public:

    MoveCommand();

    MoveCommand(const int& new_time, const int& new_speed);

    MoveCommand(const MoveCommand& commands);

    ~MoveCommand();

    int get_speed() const;

    virtual int get_radius() const;

    virtual int get_time() const;

    virtual bool is_rotation() const;

    bool operator==(const MoveCommand& other) const;

    bool operator!=(const MoveCommand& other) const;

    friend std::ostream& operator<<(std::ostream& stream, const MoveCommand& commands);

private:
    int speed = 0;
protected:
    int current_time = 0;                   // measured in minutes from the beginning of the moving
};

class Rotation : public MoveCommand {
public:
    Rotation();

    Rotation(const int& time, const int& new_radius);

    Rotation(const Rotation& command);

    ~Rotation();

    int get_radius() const;

    bool is_rotation() const;
private:
    int radius = 0;
};


std::ostream& operator<<(std::ostream& stream, const MoveCommand& commands);

#endif
