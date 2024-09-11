#include "robot_simulator.h"

namespace robot_simulator {
Robot::Robot(pair<int, int> position, Bearing bearing) {
    pos = position;
    dir = bearing;
}

const pair<int, int> Robot::get_position() const {
    return pos;
}

Bearing Robot::get_bearing() const {
    return dir;
}

void Robot::turn_right() {
    dir = static_cast<Bearing>((dir + 1) % BEARING_MAX);
}

void Robot::turn_left() {
    dir = static_cast<Bearing>((dir + BEARING_MAX - 1) % BEARING_MAX);
}

void Robot::advance() {
    const int incx[] = {0, 1, 0, -1};
    const int incy[] = {1, 0, -1, 0};
    pos.first += incx[dir];
    pos.second += incy[dir];
}

void Robot::execute_sequence(string s) {
    for (char ch : s) {
        switch (ch) {
            case 'R':
                turn_right();
                break;
            case 'L':
                turn_left();
                break;
            case 'A':
                advance();
                break;
            default:
                break;
        }
    }
}
}  // namespace robot_simulator
