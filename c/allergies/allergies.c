#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int score) {
    return (score >> allergen) & 1;
}

allergen_list_t get_allergens(int score) {
    allergen_list_t ans;
    ans.count = 0;
    for (int i = ALLERGEN_EGGS; i < ALLERGEN_COUNT; i++) {
        ans.allergens[i] = is_allergic_to(i, score);
        ans.count += ans.allergens[i];
    }
    return ans;
}