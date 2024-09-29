#include "dnd_character.h"

#include <cmath>

namespace dnd_character {
int modifier(int score) {
    return floor((score - 10) / 2.0);
}

int ability() {
    return rand() % 15 + 3;
}

Character::Character() {
    strength = ability();
    dexterity = ability();
    constitution = ability();
    intelligence = ability();
    wisdom = ability();
    charisma = ability();
    hitpoints = 10 + modifier(constitution);
    return;
};
}  // namespace dnd_character
