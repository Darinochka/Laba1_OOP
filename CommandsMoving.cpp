#include <header.h>
using namespace N;
usi

CommandsMoving() {                                         // default constructor
        x = 0;
        y = 0;
        speed = 0;
    }

    CommandsMoving(const int& orig_x, const int& orig_y, const int& new_speed) {      // initialization constructor
        x = orig_x;
        y = orig_y;
        speed = new_speed;
    }

    CommandsMoving(const CommandsMoving& commands) {            // copy  constructor
        x = commands.x;
        y = commands.y;
        speed = commands.speed;
    }

    ~CommandsMoving() {
    }

    vector<int> set_speed(const int& new_time, const int& new_speed) {
        int tempTime = new_time - current_time;
        int s = tempTime * new_speed;
        x = x + s;
        current_time = new_time;
        speed = new_speed;
        return get_coord();
    }

    vector<int> set_radius(const int& new_time, const int& new_radius) {
        int tempTime = new_time - current_time;
        int alpha = (speed / new_radius) * tempTime;
        x = round(new_radius * cos(alpha) + x);
        y = round(new_radius * sin(alpha) + y);
        current_time = new_time;
        return get_coord();
    }

    vector<int> get_coord() const {          // returns coordinates
        return {x, y};
    }

    int get_speed() const {
        return speed;
    }

private:
    int x, y;                               // x and y coordinate
    int current_time = 0;                   // measured in minutes from the beginning of the moving 
    int speed = 0;
};