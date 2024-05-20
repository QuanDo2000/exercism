#include "clock.h"

#include <stdio.h>

static void to_text(int minutes, char text[]) {
    int hour = minutes / MINUTE_IN_HOUR;
    int minute = minutes % MINUTE_IN_HOUR;
    snprintf(text, MAX_STR_LEN, FORMAT_STRING, hour, minute);
}

static int to_minutes(const char* text) {
    int hour, minute;
    sscanf(text, FORMAT_STRING, &hour, &minute);
    return (hour * MINUTE_IN_HOUR) + minute;
}

static int fix_minutes(int minutes) {
    return (minutes < 0) ? MINUTE_IN_DAY + (minutes % MINUTE_IN_DAY)
                         : minutes % MINUTE_IN_DAY;
}

clock_t clock_create(int hour, int minute) {
    clock_t clock;
    to_text(fix_minutes((hour * MINUTE_IN_HOUR) + minute), clock.text);
    return clock;
}

clock_t clock_add(clock_t clock, int minute_add) {
    return clock_create(0, to_minutes(clock.text) + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
    return clock_create(0, to_minutes(clock.text) - minute_subtract);
}

bool clock_is_equal(clock_t a, clock_t b) {
    return to_minutes(a.text) == to_minutes(b.text);
}