#include "doctor_data.h"

heaven::Vessel::Vessel(std::string name, int generation, star_map::System current_system) {
    this->name = name;
    this->generation = generation;
    this->current_system = current_system;
    this->busters = 0;
}

heaven::Vessel heaven::Vessel::replicate(std::string name) {
    return Vessel{name, this->generation + 1, this->current_system};
}

void heaven::Vessel::make_buster() {
    this->busters++;
}

bool heaven::Vessel::shoot_buster() {
    return this->busters > 0 ? this->busters--, true : false;
}

std::string heaven::get_older_bob(heaven::Vessel v1, heaven::Vessel v2) {
    return v1.generation < v2.generation ? v1.name : v2.name;
}

bool heaven::in_the_same_system(heaven::Vessel v1, heaven::Vessel v2) {
    return (v1.current_system == v2.current_system);
}