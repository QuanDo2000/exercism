#if !defined(DOCTOR_DATA_H)
#define DOCTOR_DATA_H
#include <string>

namespace star_map {
enum class System {
    Sol,
    AlphaCentauri,
    BetaHydri,
    DeltaEridani,
    EpsilonEridani,
    Omicron2Eridani,
};
}

namespace heaven {
class Vessel {
   public:
    Vessel(std::string name,
           int generation,
           star_map::System current_system = star_map::System::Sol);

    std::string name;
    star_map::System current_system;
    int generation;
    int busters;

    Vessel replicate(std::string name);
    void make_buster();
    bool shoot_buster();
};

std::string get_older_bob(Vessel v1, Vessel v2);
bool in_the_same_system(Vessel v1, Vessel v2);
}  // namespace heaven
#endif