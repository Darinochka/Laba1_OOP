#pragma once
#include <vector>

namespace N {
    class CommandsMoving {
    public:
        CommandsMoving() {}

        CommandsMoving(const int& orig_x, const int& orig_y, const int& new_speed) {}

        CommandsMoving(const CommandsMoving& commands) {}

        ~CommandsMoving() {}

        vector<int> set_speed(const int& new_time, const int& new_speed) {}

        vector<int> set_radius(const int& new_time, const int& new_radius) {}

        vector<int> get_coord() const {}

        int get_speed() const {}

    private:
        int x, y;                               // x and y coordinate
        int current_time = 0;                   // measured in minutes from the beginning of the moving 
        int speed = 0;
    };
}
