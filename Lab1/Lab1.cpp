// var 5
// Rustamova Darina
/*Студенты с кафедры робототехники запускают радиоуправляемый автомобиль.На автомобиль ещё не успели поставить GPS - модуль,
поэтому его местоположение приходится вычислять по переданным с пульта командам.Напишите программу, позволяющую определить
координаты автомобиля на основании переданных с пульта команд.
1. Команда движения : Шаг с параметрами текущее время, скорость
2. Последовательность команд(очередь команд движения и поворота) : расчёт координат автомобиля в заданное время
3. Команда поворота : текущее время, радиус поворота(положительный - против часовой стрелки, отрицательный - по часовой) */

#include <iostream>
#include <vector>
#include <cassert>
#include <fstream>
#include "header.h"
using namespace std;

void print(const Queue& queue) {
    Queue::Iterator iter;

    for (iter = queue.begin(); iter != queue.end(); iter++) {
        cout << iter << ": " << *iter << endl;
    }
}

int main()
{
    // testing of first part
    {
        cout << "Testing of first part..." << endl;

        CommandsMoving commands1;
        CommandsMoving commands2(0, 0, 0);
        CommandsMoving commands3(3, 2, 2);
        CommandsMoving commands4(commands3);
        vector<int> a = { 0, 0 };
        vector<int> b = { 3, 2 };
        int alpha;

        assert(commands1.get_coord() == a);
        assert(commands1.get_speed() == 0);

        assert(commands2.get_coord() == a);
        assert(commands2.get_speed() == 0);

        assert(commands3.get_coord() == b);
        assert(commands3.get_speed() == 2);

        assert(commands4.get_coord() == commands3.get_coord());
        assert(commands4.get_speed() == commands3.get_speed());

        a[0] = 0 + (5 - 0) * 5;                     // prev_x + (curr_time - prev_time) * speed
        a[1] = 0;                                   // prev_y
        assert(commands1.set_speed(5, 5) == a);

        alpha = (5 / 2) * (8 - 5);                  // rotation angle = (speed / radius) * (curr_time - prev_time)
        a[0] = round(2 * cos(alpha) + 25);          // new_x = round(radius * cos(alpha) + prev_x
        a[1] = round(2 * sin(alpha) + 0);           // new_y = round(radius * sin(alpha) + prev_y
        assert(commands1.set_radius(8, 2) == a);

        b[0] = 3 + (1 - 0) * 8;                     // prev_x + (curr_time - prev_time) * speed
        b[1] = 2;                                   // prev_y
        assert(commands3.set_speed(1, 8) == b);

        alpha = (8 / 10) * (5 - 0);                 // rotation angle = (speed / radius) * (curr_time - prev_time)
        b[0] = round(10 * cos(alpha) + 11);         // new_x = round(radius * cos(alpha) + prev_x
        b[1] = round(10 * sin(alpha) + 2);          // new_y = round(radius * sin(alpha) + prev_y
        assert(commands3.set_radius(5, 10) == b);

        cout << "Testing of first part is complete!" << endl;
    }

    // testing of second part
    {
        cout << "Testing of second part..." << endl;

        ifstream input("input.txt");
        ifstream input3("input3.txt");
        ofstream output("output.txt");
        ofstream output3("output3.txt");

        Queue queue1, queue3;
        queue1.load_file(input);
        queue3.load_file(input3);

        Queue queue2(queue1);

        cout << "Queue 1: " << endl; print(queue1);
        cout << "Queue 2: " << endl; print(queue2);
        cout << "Queue 3: " << endl; print(queue3);

        assert((queue1 == queue2) == true);
        assert((queue2 != queue3) == true);

        queue1.enqueue(CommandsMoving(2, 3, 10));
        cout << "Add (2, 3, 10) to queue1: " << endl; print(queue1);
        cout << "Unchanged queue2: " << endl; print(queue2);

        assert(queue1.dequeue() == CommandsMoving(0, 0, 1));
        assert(queue2.dequeue() == CommandsMoving(0, 0, 1));

        cout << "Saving..." << endl;
        queue1.save_file(output);
        queue3.save_file(output3);

        cout << "Clearing..." << endl;
        queue1.clear();
        assert(queue1 == Queue());

        queue3.clear();
        assert(queue3 == Queue());

        cout << "Successful!" << endl;

    }
    cout << "Successful testing!" << endl;
    return 0;
}

