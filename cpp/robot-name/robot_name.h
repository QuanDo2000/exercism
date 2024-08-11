#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H

#include <string>
#include <unordered_set>

using namespace std;

namespace robot_name {

static unordered_set<string> names;

string generate_name();

class robot {
   private:
    string _name;

   public:
    robot();
    string name() const;
    void reset();
};
}  // namespace robot_name

#endif  // ROBOT_NAME_H