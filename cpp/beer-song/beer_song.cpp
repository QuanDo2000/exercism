#include "beer_song.h"

#include <iostream>
#include <sstream>

namespace beer_song {
static const string FIRST_LINE[] = {
    "No more bottles of beer on the wall, no more bottles of beer.",
    "1 bottle of beer on the wall, 1 bottle of beer.",
    " bottles of beer on the wall, ",
    " bottles of beer.",
};
static const string SECOND_LINE[] = {
    "Go to the store and buy some more, 99 bottles of beer on the wall.",
    "Take it down and pass it around, no more bottles of beer on the wall.",
    "Take one down and pass it around, 1 bottle of beer on the wall.",
    "Take one down and pass it around, ",
    " bottles of beer on the wall.",
};

string verse(int n) {
    ostringstream os;
    if (n > 1) {
        os << n << FIRST_LINE[2] << n << FIRST_LINE[2 + 1] << '\n';
    } else {
        os << FIRST_LINE[n] << '\n';
    }
    if (n - 1 > 1) {
        os << SECOND_LINE[3] << n - 1 << SECOND_LINE[3 + 1] << '\n';
    } else {
        os << SECOND_LINE[n] << '\n';
    }
    return os.str();
}

string sing(int start, int end) {
    string ans;
    for (int i = start; i >= end; i--) {
        ans += verse(i);
        if (i != end) ans += '\n';
    }
    return ans;
}

string sing(int n) {
    return sing(n, 0);
}
}  // namespace beer_song
