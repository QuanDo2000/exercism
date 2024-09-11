#if !defined(ROBOT_SIMULATOR_H)
#define ROBOT_SIMULATOR_H

#include <string>
#include <utility>

using namespace std;

namespace robot_simulator {
enum Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    BEARING_MAX,
};

class Robot {
   private:
    pair<int, int> pos;
    Bearing dir;

   public:
    Robot(pair<int, int> position = {0, 0}, Bearing bearing = Bearing::NORTH);
    const pair<int, int> get_position() const;
    Bearing get_bearing() const;
    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(string s);
};
}  // namespace robot_simulator

#endif  // ROBOT_SIMULATOR_H