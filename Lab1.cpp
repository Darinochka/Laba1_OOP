// var 5
// Rustamova Darina
// speed m/s


#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


class CommandsMoving {
public:
    CommandsMoving() {                                         // default constructor
        x = 0;
        y = 0;
        speed = 0;
    }

    CommandsMoving(const int& orig_x, const int& orig_y) {      // initialization constructor
        x = orig_x;
        y = orig_y;
        speed = 0;
    }

    CommandsMoving(const CommandsMoving& commands) {            // copy  constructor
        x = commands.x;
        y = commands.y;
        speed = commands.speed;
    }

    ~CommandsMoving() {
    }

    vector<int> setSpeed(const int& new_time, const int& new_speed) {
        int tempTime = new_time - current_time;
        int s = tempTime * new_speed;
        x = x + s;
        current_time = new_time;
        speed = new_speed;
        return getCoord();
    }

    vector<int> setRoute(const int& new_time, const int& new_radius) {
        int tempTime = new_time - current_time;
        int alpha = (speed / new_radius) * tempTime;
        x = round(new_radius * cos(alpha) + x);
        y = round(new_radius * sin(alpha) + y);
        current_time = new_time;
        return getCoord();
    }

    vector<int> getCoord() const {          // returns coordinates
        return {x, y};
    }

private:
    int x, y;                               // x and y coordinate
    int current_time = 0;                    // measured in minutes from the beginning of the moving 
    int speed = 0;
};


int main()
{
    // testing of first task
    {
        cout << "Testing of first task..." << endl;

        CommandsMoving commands1;
        CommandsMoving commands2(0, 0);
        CommandsMoving commands3(3, 2);
        CommandsMoving commands4(commands3);
        vector<int> a = { 0, 0 };
        vector<int> b = { 3, 2 };

        assert(commands1.getCoord() == a);
        assert(commands2.getCoord() == a);
        assert(commands3.getCoord() == b);
        assert(commands4.getCoord() == commands3.getCoord());

        a = { 25, 0 };
        assert(commands1.setSpeed(5, 5) == a);

        a = { 27, -1 };
        assert(commands1.setRoute(8, 2) == a);

        b = { 11, 2 };
        assert(commands3.setSpeed(1, 8) == b);

        b = {21, 2};
        assert(commands3.setRoute(5, 10) == b);
        
        cout << "Testing of first task is complete!" << endl;
    }

    cout << "Successful testing!" << endl;
    return 0;
}
