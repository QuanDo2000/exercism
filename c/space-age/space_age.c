#include "space_age.h"

static const int MAX_PLANETS = 7;
static const int EARTH_YEAR_SECONDS = 31557600;
static const float RATIOS[] = {
    0.2408467, 0.61519726, 1.0, 1.8808158,
    11.862615, 29.447498, 84.016846, 164.79132};

float age(planet_t planet, int64_t seconds) {
    if (planet < 0 || planet > (planet_t)MAX_PLANETS) {
        return -1.0;
    }
    float earth_years = seconds / EARTH_YEAR_SECONDS;
    float ans = earth_years / RATIOS[planet];
    return ans;
}