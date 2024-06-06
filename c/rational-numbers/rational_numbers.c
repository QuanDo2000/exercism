#include "rational_numbers.h"

#include <math.h>

static int gcd(int a, int b) {
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;

    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

rational_t add(rational_t r1, rational_t r2) {
    rational_t r = {
        .numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator,
        .denominator = r1.denominator * r2.denominator,
    };
    return reduce(r);
}

rational_t subtract(rational_t r1, rational_t r2) {
    rational_t r = {
        .numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator,
        .denominator = r1.denominator * r2.denominator,
    };
    return reduce(r);
}

rational_t multiply(rational_t r1, rational_t r2) {
    rational_t r = {
        .numerator = r1.numerator * r2.numerator,
        .denominator = r1.denominator * r2.denominator,
    };
    return reduce(r);
}

rational_t divide(rational_t r1, rational_t r2) {
    rational_t r = {
        .numerator = r1.numerator * r2.denominator,
        .denominator = r1.denominator * r2.numerator,
    };
    return reduce(r);
}

rational_t absolute(rational_t r) {
    rational_t ans = reduce(r);
    if (ans.numerator < 0) ans.numerator *= -1;
    return ans;
}

rational_t exp_rational(rational_t r, int16_t power) {
    rational_t ans;
    if (power >= 0) {
        ans.numerator = pow(r.numerator, power);
        ans.denominator = pow(r.denominator, power);
    } else {
        ans.numerator = pow(r.denominator, power * -1);
        ans.denominator = pow(r.numerator, power * -1);
    }
    return reduce(ans);
}

float exp_real(int16_t num, rational_t r) {
    return pow(pow(num, r.numerator), 1.0 / r.denominator);
}

rational_t reduce(rational_t r) {
    int g = gcd(r.numerator, r.denominator);
    int flip = r.denominator < 0 ? -1 : 1;
    return (rational_t){
        .numerator = r.numerator / g * flip,
        .denominator = r.denominator / g * flip,
    };
}