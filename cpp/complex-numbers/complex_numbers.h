#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {
class Complex {
   private:
    double _real;
    double _imag;

   public:
    Complex(double real, double imag);
    double real() const;
    double imag() const;

    Complex operator+(const Complex& rhs) const;
    Complex operator-(const Complex& rhs) const;
    Complex operator*(const Complex& rhs) const;
    Complex operator/(const Complex& rhs) const;

    double abs() const;
    Complex conj() const;
    Complex exp() const;
};

Complex operator+(const Complex& lhs, const double& rhs);
Complex operator-(const Complex& lhs, const double& rhs);
Complex operator*(const Complex& lhs, const double& rhs);
Complex operator/(const Complex& lhs, const double& rhs);

Complex operator+(const double& lhs, const Complex& rhs);
Complex operator-(const double& lhs, const Complex& rhs);
Complex operator*(const double& lhs, const Complex& rhs);
Complex operator/(const double& lhs, const Complex& rhs);
}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
