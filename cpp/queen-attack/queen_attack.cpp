#include "queen_attack.h"

#include <stdexcept>

namespace queen_attack {
chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black) {
    if (white.first < 0 || white.second < 0 ||
        white.first > 7 || white.second > 7 ||
        black.first < 0 || black.second < 0 ||
        black.first > 7 || black.second > 7 ||
        (white.first == black.first && white.second == black.second))
        throw std::domain_error("invalid position");

    this->w = white;
    this->b = black;
}

std::pair<int, int> chess_board::white() const {
    return this->w;
}

std::pair<int, int> chess_board::black() const {
    return this->b;
}

bool chess_board::can_attack() const {
    return (this->w.first == this->b.first ||
            this->w.second == this->b.second ||
            abs(this->w.first - this->b.first) == abs(this->w.second - this->b.second));
}
}  // namespace queen_attack
