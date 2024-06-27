#ifndef ZEBRA_PUZZLE_H
#define ZEBRA_PUZZLE_H

#define N 5
#define OWNER_OFFSET (N)
#define COLOR_OFFSET (N * 2)
#define PET_OFFSET (N * 3)
#define DRINK_OFFSET (N * 4)
#define SMOKE_OFFSET (N * 5)

#define ORDER(n) (1 << (n - 1))

#define ENGLISHMAN (1 << (OWNER_OFFSET + 0))
#define SPANIARD (1 << (OWNER_OFFSET + 1))
#define UKRAINIAN (1 << (OWNER_OFFSET + 2))
#define NORWEGIAN (1 << (OWNER_OFFSET + 3))
#define JAPANESE (1 << (OWNER_OFFSET + 4))

#define RED (1 << (COLOR_OFFSET + 0))
#define GREEN (1 << (COLOR_OFFSET + 1))
#define IVORY (1 << (COLOR_OFFSET + 2))
#define YELLOW (1 << (COLOR_OFFSET + 3))
#define BLUE (1 << (COLOR_OFFSET + 4))

#define DOG (1 << (PET_OFFSET + 0))
#define SNAILS (1 << (PET_OFFSET + 1))
#define FOX (1 << (PET_OFFSET + 2))
#define HORSE (1 << (PET_OFFSET + 3))
#define ZEBRA (1 << (PET_OFFSET + 4))

#define COFFEE (1 << (DRINK_OFFSET + 0))
#define TEA (1 << (DRINK_OFFSET + 1))
#define MILK (1 << (DRINK_OFFSET + 2))
#define OJ (1 << (DRINK_OFFSET + 3))
#define WATER (1 << (DRINK_OFFSET + 4))

#define OLD_GOLD (1 << (SMOKE_OFFSET + 0))
#define KOOLS (1 << (SMOKE_OFFSET + 1))
#define CHESTERFIELDS (1 << (SMOKE_OFFSET + 2))
#define LUCKY_STRIKE (1 << (SMOKE_OFFSET + 3))
#define PARLIAMENTS (1 << (SMOKE_OFFSET + 4))

#define EVERYTHING ((1 << (N * (N + 1))) - 1)

#define ORDER_MASK(h) ((h) & ((1 << N) - 1))
#define OWNER_MASK(h) (((h) & (((1 << N) - 1) << OWNER_OFFSET)) >> OWNER_OFFSET)

#define HAS(h, attr) (((h) & (attr)) != 0)
#define IMPLIES(a, b) (!(a) || (b))

#define RIGHT_OF(h1, h2) (ORDER_MASK(h1) == (ORDER_MASK(h2) << 1))
#define NEXT_DOOR(h1, h2) (RIGHT_OF(h1, h2) || RIGHT_OF(h2, h1))

#define MAX_HOUSES (N * N * N * N * N * N)

typedef unsigned int house_t;

typedef struct puzzle {
    house_t house[N];
} puzzle_t;

typedef struct {
    const char *drinks_water;
    const char *owns_zebra;
} solution_t;

solution_t solve_puzzle(void);

#endif
