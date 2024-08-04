#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

namespace allergies {
const vector<string> ALLERGENS = {
    "eggs",
    "peanuts",
    "shellfish",
    "strawberries",
    "tomatoes",
    "chocolate",
    "pollen",
    "cats",
};

class allergies {
   private:
    unordered_set<string> items;

   public:
    bool is_allergic_to(string allergy) const;
    unordered_set<string> get_allergies() const;
    allergies(int score);
};

allergies allergy_test(int score);
}  // namespace allergies

#endif  // ALLERGIES_H