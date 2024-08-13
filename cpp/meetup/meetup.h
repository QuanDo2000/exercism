#if !defined(MEETUP_H)
#define MEETUP_H

#include <boost/date_time/gregorian/gregorian.hpp>

using namespace boost;

namespace meetup {
static const int BEFORE_FIRST_TEENTH_DAY = 12;
class scheduler {
   private:
    gregorian::date first_day;
    date_time::months_of_year m;
    int y;
    gregorian::date date_on_day(int day) const;
    gregorian::date anyteenth(date_time::weekdays weekday) const;
    gregorian::date nth_any(gregorian::nth_kday_of_month::week_num nth, date_time::weekdays weekday) const;
    gregorian::date first_any(date_time::weekdays weekday) const;
    gregorian::date second_any(date_time::weekdays weekday) const;
    gregorian::date third_any(date_time::weekdays weekday) const;
    gregorian::date fourth_any(date_time::weekdays weekday) const;
    gregorian::date last_any(date_time::weekdays weekday) const;

   public:
    scheduler(date_time::months_of_year month, int year);
    gregorian::date monteenth() const;
    gregorian::date tuesteenth() const;
    gregorian::date wednesteenth() const;
    gregorian::date thursteenth() const;
    gregorian::date friteenth() const;
    gregorian::date saturteenth() const;
    gregorian::date sunteenth() const;

    gregorian::date first_monday() const;
    gregorian::date first_tuesday() const;
    gregorian::date first_wednesday() const;
    gregorian::date first_thursday() const;
    gregorian::date first_friday() const;
    gregorian::date first_saturday() const;
    gregorian::date first_sunday() const;

    gregorian::date second_monday() const;
    gregorian::date second_tuesday() const;
    gregorian::date second_wednesday() const;
    gregorian::date second_thursday() const;
    gregorian::date second_friday() const;
    gregorian::date second_saturday() const;
    gregorian::date second_sunday() const;

    gregorian::date third_monday() const;
    gregorian::date third_tuesday() const;
    gregorian::date third_wednesday() const;
    gregorian::date third_thursday() const;
    gregorian::date third_friday() const;
    gregorian::date third_saturday() const;
    gregorian::date third_sunday() const;

    gregorian::date fourth_monday() const;
    gregorian::date fourth_tuesday() const;
    gregorian::date fourth_wednesday() const;
    gregorian::date fourth_thursday() const;
    gregorian::date fourth_friday() const;
    gregorian::date fourth_saturday() const;
    gregorian::date fourth_sunday() const;

    gregorian::date last_monday() const;
    gregorian::date last_tuesday() const;
    gregorian::date last_wednesday() const;
    gregorian::date last_thursday() const;
    gregorian::date last_friday() const;
    gregorian::date last_saturday() const;
    gregorian::date last_sunday() const;
};
}  // namespace meetup

#endif  // MEETUP_H