#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

using namespace std;

namespace date_independent {
static const int MINUTES_IN_HOUR = 60;
static const int MINUTES_IN_DAY = 24 * MINUTES_IN_HOUR;
class clock {
   private:
    int minutes;
    void fix();
    clock(int minute);

   public:
    static clock at(int const hour, int const minute);
    clock& plus(int const minute);

    operator string() const;
    bool operator==(const clock& rhs) const;
    bool operator!=(const clock& rhs) const;
};
}  // namespace date_independent

#endif  // CLOCK_H