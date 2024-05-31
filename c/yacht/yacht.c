#include "yacht.h"

static void count_dice(dice_t dice, int count[NUM_FACES]) {
    for (int i = 0; i < NUM_FACES; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < NUM_DICE; i++) {
        count[dice.faces[i] - 1]++;
    }
}

static int score_num(dice_t dice, int num) {
    int ans = 0;
    for (int i = 0; i < NUM_DICE; i++) {
        if (num == -1) ans += dice.faces[i];
        if (dice.faces[i] == num) ans += num;
    }
    return ans;
}

static int score_full_house(dice_t dice) {
    int count[NUM_FACES];
    count_dice(dice, count);

    int ans = 0;
    for (int i = 0; i < NUM_FACES; i++) {
        if (count[i] == 1 || count[i] == 4 || count[i] == 5) return 0;
        ans += (i + 1) * count[i];
    }
    return ans;
}

static int score_four_of_a_kind(dice_t dice) {
    int count[NUM_FACES];
    count_dice(dice, count);

    for (int i = 0; i < NUM_FACES; i++) {
        if (count[i] == 4 || count[i] == 5) return (i + 1) * 4;
    }
    return 0;
}

static int score_yatch(dice_t dice) {
    int count[NUM_FACES];
    count_dice(dice, count);

    for (int i = 0; i < NUM_FACES; i++) {
        if (count[i] == 5) return 50;
    }
    return 0;
}

static int score_straight(dice_t dice, char big) {
    int count[NUM_FACES];
    count_dice(dice, count);

    for (int i = 0; i < NUM_FACES; i++) {
        if (count[i] != 1 && count[i] != 0) return 0;
    }
    if ((big == 0 && count[NUM_FACES - 1] == 0) ||
        (big != 0 && count[0] == 0)) return 30;
    return 0;
}

int score(dice_t dice, category_t category) {
    switch (category) {
        case ONES:
        case TWOS:
        case THREES:
        case FOURS:
        case FIVES:
        case SIXES:
            return score_num(dice, category + 1);
        case FULL_HOUSE:
            return score_full_house(dice);
        case FOUR_OF_A_KIND:
            return score_four_of_a_kind(dice);
        case LITTLE_STRAIGHT:
        case BIG_STRAIGHT:
            return score_straight(dice, category - LITTLE_STRAIGHT);
        case CHOICE:
            return score_num(dice, -1);
        case YACHT:
            return score_yatch(dice);
        default:
            return 0;
    }
    return 0;
}