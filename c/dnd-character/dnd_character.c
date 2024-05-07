#include "dnd_character.h"

#include <stdlib.h>
#include <time.h>

#define MAX_ROLL 6
#define NUM_ROLLS 4

int modifier(int score) {
    int modifier = (score - 10) / 2;
    return modifier - (score <= 10 && score % 2 != 0);
}

int ability(void) {
    srand(time(NULL));

    int min = MAX_ROLL + 1;
    int sum = 0;
    for (int i = 0; i < NUM_ROLLS; i++) {
        int roll = rand() % MAX_ROLL + 1;
        sum += roll;
        if (roll < min) {
            min = roll;
        }
    }
    return sum - min;
}

dnd_character_t make_dnd_character(void) {
    dnd_character_t new_char;

    new_char.strength = ability();
    new_char.dexterity = ability();
    new_char.constitution = ability();
    new_char.intelligence = ability();
    new_char.wisdom = ability();
    new_char.charisma = ability();
    new_char.hitpoints = modifier(new_char.constitution) + 10;

    return new_char;
}