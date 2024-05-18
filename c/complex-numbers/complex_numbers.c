#include "complex_numbers.h"

#include <math.h>

complex_t c_add(complex_t a, complex_t b) {
    complex_t ans;
    ans.real = a.real + b.real;
    ans.imag = a.imag + b.imag;
    return ans;
}

complex_t c_sub(complex_t a, complex_t b) {
    complex_t ans;
    ans.real = a.real - b.real;
    ans.imag = a.imag - b.imag;
    return ans;
}

complex_t c_mul(complex_t a, complex_t b) {
    complex_t ans;
    ans.real = (a.real * b.real) - (a.imag * b.imag);
    ans.imag = (a.imag * b.real) + (a.real * b.imag);
    return ans;
}

complex_t c_div(complex_t a, complex_t b) {
    complex_t ans;
    double denominator = b.real * b.real + b.imag * b.imag;
    ans.real = (a.real * b.real + a.imag * b.imag) / denominator;
    ans.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return ans;
}

double c_abs(complex_t x) {
    return sqrt(x.real * x.real + x.imag * x.imag);
}

complex_t c_conjugate(complex_t x) {
    complex_t ans;
    ans.real = x.real;
    ans.imag = -x.imag;
    return ans;
}

double c_real(complex_t x) {
    return x.real;
}

double c_imag(complex_t x) {
    return x.imag;
}

complex_t c_exp(complex_t x) {
    complex_t ans;
    double t = exp(x.real);
    ans.real = t * cos(x.imag);
    ans.imag = t * sin(x.imag);
    return ans;
}
