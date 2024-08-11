#include "robot_name.h"

#include <cstdlib>

namespace robot_name {
string random_name() {
    string name = "";
    name += rand() % ('Z' - 'A') + 'A';
    name += rand() % ('Z' - 'A') + 'A';
    name += rand() % 10 + '0';
    name += rand() % 10 + '0';
    name += rand() % 10 + '0';
    return name;
}

string generate_name() {
    string temp_name = random_name();
    while (names.count(temp_name) != 0) {
        temp_name = random_name();
    }
    names.insert(temp_name);
    return temp_name;
}

robot::robot() {
    this->_name = generate_name();
};
string robot::name() const {
    return this->_name;
};
void robot::reset() {
    this->_name = generate_name();
}
}  // namespace robot_name
