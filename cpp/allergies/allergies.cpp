#include "allergies.h"

namespace allergies {
bool allergies::is_allergic_to(string allergen) const {
    return (this->items.count(allergen) != 0);
}

unordered_set<string> allergies::get_allergies() const {
    return (this->items);
}

allergies::allergies(int score) {
    this->items.clear();
    for (size_t i = 0; i < ALLERGENS.size(); i++) {
        if (score & (1 << i)) {
            this->items.insert(ALLERGENS[i]);
        }
    }
}

allergies allergy_test(int score) {
    return allergies(score);
}
}  // namespace allergies
