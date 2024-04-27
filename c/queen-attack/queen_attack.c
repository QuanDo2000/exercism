#include "queen_attack.h"

#include <stdlib.h>

const int MAX_SIZE = 7;
const int MIN_SIZE = 0;

static char is_invalid_position(position_t pos) {
    return (pos.column < MIN_SIZE || pos.column > MAX_SIZE ||
            pos.row < MIN_SIZE || pos.row > MAX_SIZE);
}

static char is_invalid_positions(position_t pos1, position_t pos2) {
    return (is_invalid_position(pos1) || is_invalid_position(pos2) ||
            (pos1.row == pos2.row && pos1.column == pos2.column));
}

static char is_same_row(position_t pos1, position_t pos2) {
    return pos1.row == pos2.row;
}

static char is_same_column(position_t pos1, position_t pos2) {
    return pos1.column == pos2.column;
}

static char is_on_diagonal(position_t pos1, position_t pos2) {
    return (abs(pos1.column - pos2.column) == abs(pos1.row - pos2.row));
}

static char is_on_straight_or_diagonal(position_t pos1, position_t pos2) {
    return is_same_row(pos1, pos2) || is_same_column(pos1, pos2) ||
           is_on_diagonal(pos1, pos2);
}

attack_status_t can_attack(position_t q1, position_t q2) {
    if (is_invalid_positions(q1, q2)) {
        return INVALID_POSITION;
    }
    return is_on_straight_or_diagonal(q1, q2);
}