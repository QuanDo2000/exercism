#include "grade_school.h"

#include <algorithm>

namespace grade_school {
const std::map<int, std::vector<std::string>>& school::roster() const {
    return this->ros;
}

void school::add(std::string name, int grade) {
    std::vector<std::string>& g = this->ros[grade];
    g.push_back(name);
    std::sort(g.begin(), g.end());
}

std::vector<std::string> school::grade(int grade) const {
    return this->ros.find(grade)->second;
}
}  // namespace grade_school
