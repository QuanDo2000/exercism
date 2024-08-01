#include "say.h"

#include <stdexcept>

namespace say {
std::string ONES[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::string TENS[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
std::string TEENS[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
std::string THOUSANDS[] = {"thousand", "million", "billion"};

std::string print_tens(int tens) {
    if (tens > 0) return TENS[tens];
    return "";
}

std::string print_ones(int ones) {
    if (ones > 0) return ONES[ones];
    return "";
}

std::string print_chunk(int chunk) {
    std::string ans = "";
    if (chunk >= 100) {
        int hundred = chunk / 100;
        ans += print_ones(hundred) + " hundred";
    }

    if (chunk < 10 || chunk >= 20) {
        int tens = (chunk / 10) % 10;
        int ones = chunk % 10;
        if (ans.length() > 0 && tens > 0) ans += " ";
        ans += print_tens(tens);
        if (tens != 0 && ones != 0) ans += "-";
        ans += print_ones(ones);
    } else {
        ans += TEENS[chunk - 10];
    }
    return ans;
}

std::string print_thousandth(int th_idx) {
    if (th_idx > 0) return " " + THOUSANDS[th_idx - 1];
    return "";
}

std::string in_english(long long num) {
    if (num < 0 || num > 999999999999) throw std::domain_error("invalid input");
    if (num == 0) return "zero";

    std::string ans = "";

    int th_idx = 0;
    while (num > 0) {
        int chunk = num % 1000;
        std::string tmp = print_chunk(chunk);
        if (chunk != 0) tmp += print_thousandth(th_idx);
        num /= 1000;

        if (ans.length() > 0 && tmp.length() > 0) {
            tmp += " ";
        }
        ans = tmp + ans;
        th_idx++;
    }
    return ans;
}
}  // namespace say
