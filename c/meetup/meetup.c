#include "meetup.h"

#include <string.h>

static char* days_of_week[NUM_DAYS_IN_WEEK] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

static int get_day_of_week(const char* day_of_week) {
    for (int i = 0; i < NUM_DAYS_IN_WEEK; i++) {
        if (strcmp(day_of_week, days_of_week[i]) == 0) return i;
    }
    return -1;
}

static int is_leap(unsigned int year) {
    if (year % 400 == 0) return 1;
    if (year % 100 == 0) return 0;
    if (year % 4 == 0) return 1;
    return 0;
}

static int month_offset[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

static int get_month_offset(unsigned int year, unsigned int month) {
    int offset = month_offset[month - 1];
    if (is_leap(year) && month > 2) {
        offset++;
        offset %= NUM_DAYS_IN_WEEK;
    }
    return offset;
}

static int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static int get_days_in_month(unsigned int year, unsigned int month) {
    if (is_leap(year) && month == 2) return days_in_month[month - 1] + 1;
    return days_in_month[month - 1];
}

int meetup_day_of_month(unsigned int year, unsigned int month, const char* week, const char* day_of_week) {
    int a = year - 1;
    // Gauss's algorithm
    int fdow = (1 + get_month_offset(year, month) +
                5 * (a % 4) +
                4 * (a % 100) +
                6 * (a % 400)) %
               7;
    int dow = get_day_of_week(day_of_week);
    int dow_diff = dow - fdow;
    if (dow_diff < 0) dow_diff += 7;

    int dom = 1 + dow_diff;
    if (strcmp(week, "first") == 0) return dom;
    if (strcmp(week, "second") == 0) return dom + 7;
    if (strcmp(week, "third") == 0) return dom + 7 * 2;
    if (strcmp(week, "fourth") == 0) return dom + 7 * 3;
    if (strcmp(week, "last") == 0) {
        while (dom + 7 <= get_days_in_month(year, month)) dom += 7;
        return dom;
    }
    if (strcmp(week, "teenth") == 0) {
        while (dom < 13) dom += 7;
        return dom;
    }
    return dom;
}