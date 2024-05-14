#include "gigasecond.h"

#include <time.h>

#define GIGASECOND 1e9;

void gigasecond(time_t input, char* output, size_t size) {
    input += GIGASECOND;
    struct tm* time = gmtime(&input);
    strftime(output, size, "%Y-%m-%d %H:%M:%S", time);
    return;
}