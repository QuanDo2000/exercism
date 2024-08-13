#include "meetup.h"

namespace meetup {
scheduler::scheduler(date_time::months_of_year month, int year) {
    this->m = month;
    this->y = year;
}

gregorian::date scheduler::date_on_day(int day) const {
    return gregorian::date(this->y, this->m, day);
}

gregorian::date scheduler::anyteenth(date_time::weekdays weekday) const {
    gregorian::first_day_of_the_week_after fdaf(weekday);
    return fdaf.get_date(date_on_day(BEFORE_FIRST_TEENTH_DAY));
}

gregorian::date scheduler::monteenth() const {
    return anyteenth(gregorian::Monday);
}
gregorian::date scheduler::tuesteenth() const {
    return anyteenth(gregorian::Tuesday);
}
gregorian::date scheduler::wednesteenth() const {
    return anyteenth(gregorian::Wednesday);
};
gregorian::date scheduler::thursteenth() const {
    return anyteenth(gregorian::Thursday);
};
gregorian::date scheduler::friteenth() const {
    return anyteenth(gregorian::Friday);
};
gregorian::date scheduler::saturteenth() const {
    return anyteenth(gregorian::Saturday);
};
gregorian::date scheduler::sunteenth() const {
    return anyteenth(gregorian::Sunday);
};

gregorian::date scheduler::nth_any(gregorian::nth_kday_of_month::week_num nth, date_time::weekdays weekday) const {
    gregorian::nth_day_of_the_week_in_month ndm(nth, weekday, this->m);
    return ndm.get_date(this->y);
}

gregorian::date scheduler::first_any(date_time::weekdays weekday) const {
    return nth_any(gregorian::nth_day_of_the_week_in_month::first, weekday);
}
gregorian::date scheduler::second_any(date_time::weekdays weekday) const {
    return nth_any(gregorian::nth_day_of_the_week_in_month::second, weekday);
}
gregorian::date scheduler::third_any(date_time::weekdays weekday) const {
    return nth_any(gregorian::nth_day_of_the_week_in_month::third, weekday);
}
gregorian::date scheduler::fourth_any(date_time::weekdays weekday) const {
    return nth_any(gregorian::nth_day_of_the_week_in_month::fourth, weekday);
}
gregorian::date scheduler::last_any(date_time::weekdays weekday) const {
    return nth_any(gregorian::nth_day_of_the_week_in_month::fifth, weekday);
}

gregorian::date scheduler::first_monday() const {
    return first_any(gregorian::Monday);
};
gregorian::date scheduler::first_tuesday() const {
    return first_any(gregorian::Tuesday);
};
gregorian::date scheduler::first_wednesday() const {
    return first_any(gregorian::Wednesday);
};
gregorian::date scheduler::first_thursday() const {
    return first_any(gregorian::Thursday);
};
gregorian::date scheduler::first_friday() const {
    return first_any(gregorian::Friday);
};
gregorian::date scheduler::first_saturday() const {
    return first_any(gregorian::Saturday);
};
gregorian::date scheduler::first_sunday() const {
    return first_any(gregorian::Sunday);
};

gregorian::date scheduler::second_monday() const {
    return second_any(gregorian::Monday);
};
gregorian::date scheduler::second_tuesday() const {
    return second_any(gregorian::Tuesday);
};
gregorian::date scheduler::second_wednesday() const {
    return second_any(gregorian::Wednesday);
};
gregorian::date scheduler::second_thursday() const {
    return second_any(gregorian::Thursday);
};
gregorian::date scheduler::second_friday() const {
    return second_any(gregorian::Friday);
};
gregorian::date scheduler::second_saturday() const {
    return second_any(gregorian::Saturday);
};
gregorian::date scheduler::second_sunday() const {
    return second_any(gregorian::Sunday);
};

gregorian::date scheduler::third_monday() const {
    return third_any(gregorian::Monday);
};
gregorian::date scheduler::third_tuesday() const {
    return third_any(gregorian::Tuesday);
};
gregorian::date scheduler::third_wednesday() const {
    return third_any(gregorian::Wednesday);
};
gregorian::date scheduler::third_thursday() const {
    return third_any(gregorian::Thursday);
};
gregorian::date scheduler::third_friday() const {
    return third_any(gregorian::Friday);
};
gregorian::date scheduler::third_saturday() const {
    return third_any(gregorian::Saturday);
};
gregorian::date scheduler::third_sunday() const {
    return third_any(gregorian::Sunday);
};

gregorian::date scheduler::fourth_monday() const {
    return fourth_any(gregorian::Monday);
};
gregorian::date scheduler::fourth_tuesday() const {
    return fourth_any(gregorian::Tuesday);
};
gregorian::date scheduler::fourth_wednesday() const {
    return fourth_any(gregorian::Wednesday);
};
gregorian::date scheduler::fourth_thursday() const {
    return fourth_any(gregorian::Thursday);
};
gregorian::date scheduler::fourth_friday() const {
    return fourth_any(gregorian::Friday);
};
gregorian::date scheduler::fourth_saturday() const {
    return fourth_any(gregorian::Saturday);
};
gregorian::date scheduler::fourth_sunday() const {
    return fourth_any(gregorian::Sunday);
};

gregorian::date scheduler::last_monday() const {
    return last_any(gregorian::Monday);
};
gregorian::date scheduler::last_tuesday() const {
    return last_any(gregorian::Tuesday);
};
gregorian::date scheduler::last_wednesday() const {
    return last_any(gregorian::Wednesday);
};
gregorian::date scheduler::last_thursday() const {
    return last_any(gregorian::Thursday);
};
gregorian::date scheduler::last_friday() const {
    return last_any(gregorian::Friday);
};
gregorian::date scheduler::last_saturday() const {
    return last_any(gregorian::Saturday);
};
gregorian::date scheduler::last_sunday() const {
    return last_any(gregorian::Sunday);
};
}  // namespace meetup
