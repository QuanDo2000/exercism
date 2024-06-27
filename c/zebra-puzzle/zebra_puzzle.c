#include "zebra_puzzle.h"

#include <stdlib.h>

static char* nationality[N] = {
    "Englishman",
    "Spaniard",
    "Ukrainian",
    "Norwegian",
    "Japanese",
};

static unsigned int house_rules(house_t h) {
    return (HAS(h, ENGLISHMAN) == HAS(h, RED)) &&
           (HAS(h, SPANIARD) == HAS(h, DOG)) &&
           (HAS(h, COFFEE) == HAS(h, GREEN)) &&
           (HAS(h, UKRAINIAN) == HAS(h, TEA)) &&
           IMPLIES(HAS(h, GREEN), !HAS(h, ORDER(1))) &&
           IMPLIES(HAS(h, IVORY), !HAS(h, ORDER(5))) &&
           (HAS(h, OLD_GOLD) == HAS(h, SNAILS)) &&
           (HAS(h, KOOLS) == HAS(h, YELLOW)) &&
           (HAS(h, MILK) == HAS(h, ORDER((N + 1) / 2))) &&
           (HAS(h, NORWEGIAN) == HAS(h, ORDER(1))) &&
           IMPLIES(HAS(h, CHESTERFIELDS), !HAS(h, FOX)) &&
           IMPLIES(HAS(h, KOOLS), !HAS(h, HORSE)) &&
           (HAS(h, LUCKY_STRIKE) == HAS(h, OJ)) &&
           (HAS(h, JAPANESE) == HAS(h, PARLIAMENTS)) &&
           IMPLIES(HAS(h, NORWEGIAN), !HAS(h, BLUE));
}

static size_t feasible_houses(house_t* houses) {
    size_t n = 0;
    for (int order = 0; order < N; order++) {
        for (int owner = OWNER_OFFSET; owner < OWNER_OFFSET + N; owner++) {
            for (int color = COLOR_OFFSET; color < COLOR_OFFSET + N; color++) {
                for (int pet = PET_OFFSET; pet < PET_OFFSET + N; pet++) {
                    for (int drink = DRINK_OFFSET; drink < DRINK_OFFSET + N; drink++) {
                        for (int smoke = SMOKE_OFFSET; smoke < SMOKE_OFFSET + N; smoke++) {
                            house_t h = (1 << order) | (1 << owner) | (1 << color) | (1 << pet) | (1 << drink) | (1 << smoke);
                            if (house_rules(h)) {
                                houses[n++] = h;
                            }
                        }
                    }
                }
            }
        }
    }
    return n;
}

static unsigned int two_house_rules(house_t h1, house_t h2) {
    return IMPLIES(HAS(h1, GREEN) && HAS(h2, IVORY), RIGHT_OF(h1, h2)) &&
           IMPLIES(HAS(h1, CHESTERFIELDS) && HAS(h2, FOX), NEXT_DOOR(h1, h2)) &&
           IMPLIES(HAS(h1, KOOLS) && HAS(h2, HORSE), NEXT_DOOR(h1, h2)) &&
           IMPLIES(HAS(h1, NORWEGIAN) && HAS(h2, BLUE), NEXT_DOOR(h1, h2));
}

static unsigned int puzzle_rules(puzzle_t* p) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            if (!two_house_rules(p->house[i], p->house[j])) {
                return 0;
            }
        }
    }
    return 1;
}

static int compare_house(const void* a, const void* b) {
    house_t h1 = *(house_t*)a;
    house_t h2 = *(house_t*)b;
    return (int)ORDER_MASK(h1) - (int)ORDER_MASK(h2);
}

static unsigned int complete(house_t h1, house_t h2, house_t h3, house_t h4, house_t h5) {
    return (h1 | h2 | h3 | h4 | h5) == EVERYTHING;
}

static unsigned int make_puzzle(puzzle_t* puzzle, size_t n_house, house_t* houses) {
    qsort(houses, n_house, sizeof(house_t), compare_house);
    size_t idx[N + 1];
    size_t count = 0;
    for (size_t i = 0; i < n_house; i++) {
        house_t h = houses[i];
        if (ORDER_MASK(h) == (1u << count)) {
            idx[count++] = i;
        }
    }

    idx[N] = n_house;
    unsigned int found = 0;
    for (size_t hi1 = idx[0]; hi1 < idx[1]; hi1++) {
        for (size_t hi2 = idx[1]; hi2 < idx[2]; hi2++) {
            for (size_t hi3 = idx[2]; hi3 < idx[3]; hi3++) {
                for (size_t hi4 = idx[3]; hi4 < idx[4]; hi4++) {
                    for (size_t hi5 = idx[4]; hi5 < idx[5]; hi5++) {
                        house_t h1 = houses[hi1];
                        house_t h2 = houses[hi2];
                        house_t h3 = houses[hi3];
                        house_t h4 = houses[hi4];
                        house_t h5 = houses[hi5];
                        if (complete(h1, h2, h3, h4, h5)) {
                            puzzle_t p = (puzzle_t){{h1, h2, h3, h4, h5}};
                            if (puzzle_rules(&p)) {
                                if (found) return 0;
                                *puzzle = p;
                                found = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    return found;
}

static unsigned int solve(puzzle_t* p) {
    house_t houses[MAX_HOUSES];
    size_t n_house = feasible_houses(houses);
    return make_puzzle(p, n_house, houses);
}

static const char* get_owner(puzzle_t* p, house_t attr) {
    for (int i = 0; i < N; i++) {
        house_t h = p->house[i];
        if (HAS(h, attr)) {
            house_t omask = OWNER_MASK(h);
            for (int j = 0; j < N; j++) {
                if ((1u << j) == omask) {
                    return nationality[j];
                }
            }
        }
    }
    return NULL;
}

solution_t solve_puzzle(void) {
    puzzle_t p;
    solve(&p);
    solution_t ans;
    ans.drinks_water = get_owner(&p, WATER);
    ans.owns_zebra = get_owner(&p, ZEBRA);
    return ans;
}