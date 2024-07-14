#include "lasagna_master.h"

namespace lasagna_master {
int preparationTime(const std::vector<std::string> layers, const int timePerLayer) {
    return timePerLayer * layers.size();
}

struct amount quantities(const std::vector<std::string> layers) {
    struct amount ans {
        0, 0
    };
    for (auto layer : layers) {
        if (layer == "sauce") {
            ans.sauce += 0.2;
        } else if (layer == "noodles") {
            ans.noodles += 50;
        }
    }
    return ans;
}

std::vector<double> scaleRecipe(const std::vector<double>& quantities, int scale) {
    double s = scale / 2.0;
    std::vector<double> ans;
    for (auto quantity : quantities) {
        ans.push_back(quantity * s);
    }
    return ans;
}

void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList) {
    myList.back() = friendsList.back();
}
void addSecretIngredient(std::vector<std::string>& myList, const std::string secretIngredient) {
    myList.back() = secretIngredient;
}
}  // namespace lasagna_master
