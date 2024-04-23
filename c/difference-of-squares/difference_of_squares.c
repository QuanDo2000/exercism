#include "difference_of_squares.h"

unsigned int square_of_sum(unsigned int number) {
    unsigned int sum = ((number + 1) * number) / 2;
    return sum * sum;
}

unsigned int sum_of_squares(unsigned int number) {
    unsigned int result = (number * (number + 1) * ((number * 2) + 1)) / 6;
    return result;
}

unsigned int difference_of_squares(unsigned int number) {
    return square_of_sum(number) - sum_of_squares(number);
}