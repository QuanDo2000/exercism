#include "complex_numbers.h"

#include <cmath>

namespace complex_numbers {
Complex::Complex(double real, double imag) {
    this->_real = real;
    this->_imag = imag;
}

double Complex::real() const {
    return this->_real;
}

double Complex::imag() const {
    return this->_imag;
}

Complex Complex::operator+(const Complex& rhs) const {
    return Complex{this->real() + rhs.real(),
                   this->imag() + rhs.imag()};
}
Complex Complex::operator-(const Complex& rhs) const {
    return Complex{this->real() - rhs.real(),
                   this->imag() - rhs.imag()};
}
Complex Complex::operator*(const Complex& rhs) const {
    return Complex{this->real() * rhs.real() - this->imag() * rhs.imag(),
                   this->imag() * rhs.real() + this->real() * rhs.imag()};
}
Complex Complex::operator/(const Complex& rhs) const {
    double denominator = pow(rhs.real(), 2) + pow(rhs.imag(), 2);
    double real = (this->real() * rhs.real() + this->imag() * rhs.imag()) / denominator;
    double imag = (this->imag() * rhs.real() - this->real() * rhs.imag()) / denominator;
    return Complex{real, imag};
}

double Complex::abs() const {
    return sqrt(pow(this->real(), 2) + pow(this->imag(), 2));
}
Complex Complex::conj() const {
    return Complex{this->real(), -this->imag()};
}
Complex Complex::exp() const {
    double real_exp = std::exp(this->real());
    double real = real_exp * cos(this->imag());
    double imag = real_exp * sin(this->imag());
    return Complex{real, imag};
}

Complex operator+(const Complex& lhs, const double& rhs) {
    return lhs + Complex{rhs, 0};
}
Complex operator-(const Complex& lhs, const double& rhs) {
    return lhs - Complex{rhs, 0};
}
Complex operator*(const Complex& lhs, const double& rhs) {
    return lhs * Complex{rhs, 0};
}
Complex operator/(const Complex& lhs, const double& rhs) {
    return lhs / Complex{rhs, 0};
}

Complex operator+(const double& lhs, const Complex& rhs) {
    return Complex{lhs, 0} + rhs;
}
Complex operator-(const double& lhs, const Complex& rhs) {
    return Complex{lhs, 0} - rhs;
}
Complex operator*(const double& lhs, const Complex& rhs) {
    return Complex{lhs, 0} * rhs;
}
Complex operator/(const double& lhs, const Complex& rhs) {
    return Complex{lhs, 0} / rhs;
}
}  // namespace complex_numbers
