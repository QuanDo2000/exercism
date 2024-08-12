#include "clock.h"

#include <iomanip>
#include <sstream>

namespace date_independent {
void clock::fix() {
    this->minutes = (this->minutes < 0)
                        ? MINUTES_IN_DAY + (this->minutes % MINUTES_IN_DAY)
                        : this->minutes % MINUTES_IN_DAY;
}

clock::clock(int minute) {
    this->minutes = minute;
    fix();
}

clock clock::at(int const hour, int const minute) {
    return clock(hour * MINUTES_IN_HOUR + minute);
}

clock& clock::plus(int const minute) {
    this->minutes += minute;
    fix();
    return *this;
}

clock::operator string() const {
    ostringstream os;
    os << setw(2) << setfill('0') << this->minutes / MINUTES_IN_HOUR << ":" << setw(2) << setfill('0') << this->minutes % MINUTES_IN_HOUR;
    return os.str();
}

bool clock::operator==(const clock& rhs) const {
    return this->minutes == rhs.minutes;
}

bool clock::operator!=(const clock& rhs) const {
    return this->minutes != rhs.minutes;
}
}  // namespace date_independent
