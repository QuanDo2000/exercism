#ifndef YACHT_H
#define YACHT_H

#define NUM_DICE (5)
#define NUM_FACES (6)

typedef enum {
    ONES,
    TWOS,
    THREES,
    FOURS,
    FIVES,
    SIXES,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    LITTLE_STRAIGHT,
    BIG_STRAIGHT,
    CHOICE,
    YACHT
} category_t;

typedef struct {
    int faces[NUM_DICE];
} dice_t;

int score(dice_t dice, category_t category);

#endif
