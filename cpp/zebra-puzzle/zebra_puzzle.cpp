#include "zebra_puzzle.h"

namespace zebra_puzzle {
vector<string> nationality = {
    "Englishman",
    "Spaniard",
    "Ukrainian",
    "Norwegian",
    "Japanese",
};

house_t houseRules(house_t h) {
    return (HAS(h, ENGLISHMAN) == HAS(h, RED)) &&
           (HAS(h, SPANIARD) == HAS(h, DOG)) &&
           (HAS(h, COFFEE) == HAS(h, GREEN)) &&
           (HAS(h, UKRAINIAN) == HAS(h, TEA)) &&
           IMPLIES(HAS(h, GREEN), !HAS(h, ORDER(1))) &&
           IMPLIES(HAS(h, IVORY), !HAS(h, ORDER(5))) &&
           (HAS(h, OLD_GOLD) == HAS(h, SNAILS)) &&
           (HAS(h, KOOLS) == HAS(h, YELLOW)) &&
           (HAS(h, MILK) == HAS(h, ORDER((NUM + 1) / 2))) &&
           (HAS(h, NORWEGIAN) == HAS(h, ORDER(1))) &&
           IMPLIES(HAS(h, CHESTERFIELDS), !HAS(h, FOX)) &&
           IMPLIES(HAS(h, KOOLS), !HAS(h, HORSE)) &&
           (HAS(h, LUCKY_STRIKE) == HAS(h, OJ)) &&
           (HAS(h, JAPANESE) == HAS(h, PARLIAMENTS)) &&
           IMPLIES(HAS(h, NORWEGIAN), !HAS(h, BLUE));
};

void feasibleHouses(vector<house_t>& houses) {
    for (int order = 0; order < NUM; order++) {
        for (int owner = OWNER_OFFSET; owner < OWNER_OFFSET + NUM; owner++) {
            for (int color = COLOR_OFFSET; color < COLOR_OFFSET + NUM; color++) {
                for (int pet = PET_OFFSET; pet < PET_OFFSET + NUM; pet++) {
                    for (int drink = DRINK_OFFSET; drink < DRINK_OFFSET + NUM; drink++) {
                        for (int smoke = SMOKE_OFFSET; smoke < SMOKE_OFFSET + NUM; smoke++) {
                            house_t h = (1 << order) | (1 << owner) | (1 << color) | (1 << pet) | (1 << drink) | (1 << smoke);
                            if (houseRules(h)) {
                                houses.emplace_back(h);
                            }
                        }
                    }
                }
            }
        }
    }
}

house_t twoHouseRules(house_t h1, house_t h2) {
    return IMPLIES(HAS(h1, GREEN) && HAS(h2, IVORY), RIGHT_OF(h1, h2)) &&
           IMPLIES(HAS(h1, CHESTERFIELDS) && HAS(h2, FOX), NEXT_DOOR(h1, h2)) &&
           IMPLIES(HAS(h1, KOOLS) && HAS(h2, HORSE), NEXT_DOOR(h1, h2)) &&
           IMPLIES(HAS(h1, NORWEGIAN) && HAS(h2, BLUE), NEXT_DOOR(h1, h2));
}

house_t puzzleRules(vector<house_t> houses) {
    for (size_t i = 0; i < NUM; i++) {
        for (size_t j = 0; j < NUM; j++) {
            if (!twoHouseRules(houses[i], houses[j])) {
                return 0;
            }
        }
    }
    return 1;
}

bool compareHouse(const house_t& a, const house_t& b) {
    return (int)ORDER_MASK(a) < ORDER_MASK(b);
}

house_t complete(house_t h1, house_t h2, house_t h3, house_t h4, house_t h5) {
    return (h1 | h2 | h3 | h4 | h5) == EVERYTHING;
}

house_t makePuzzle(Puzzle& puzzle, vector<house_t> houses) {
    sort(houses.begin(), houses.end(), compareHouse);
    vector<size_t> idx(NUM + 1);
    size_t count = 0;
    for (size_t i = 0; i < houses.size(); i++) {
        house_t h = houses[i];
        if (ORDER_MASK(h) == (1u << count)) {
            idx[count++] = i;
        }
    }

    idx[NUM] = houses.size();
    house_t found = 0;
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
                            vector<house_t> houses = {h1, h2, h3, h4, h5};
                            if (puzzleRules(houses)) {
                                if (found) return 0;
                                puzzle.houses = houses;
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

house_t solve(Puzzle& p) {
    vector<house_t> houses;
    feasibleHouses(houses);
    return makePuzzle(p, houses);
}

const string getOwner(Puzzle& p, house_t attr) {
    for (int i = 0; i < NUM; i++) {
        house_t h = p.houses[i];
        if (HAS(h, attr)) {
            house_t omask = OWNER_MASK(h);
            for (int j = 0; j < NUM; j++) {
                if ((1u << j) == omask) {
                    return nationality[j];
                }
            }
        }
    }
    return "";
}

Solution solve() {
    Puzzle p;
    Solution ans = {"", ""};
    if (!solve(p)) return ans;
    ans.drinksWater = getOwner(p, WATER);
    ans.ownsZebra = getOwner(p, ZEBRA);
    return ans;
}
}  // namespace zebra_puzzle