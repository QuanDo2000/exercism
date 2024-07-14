#pragma once

#include <string>
#include <vector>

namespace lasagna_master {

struct amount {
    int noodles;
    double sauce;
};

int preparationTime(const std::vector<std::string> layers, const int timePerLayer = 2);
struct amount quantities(const std::vector<std::string> layers);
std::vector<double> scaleRecipe(const std::vector<double>& quantities, int scale);

void addSecretIngredient(std::vector<std::string>& myList, const std::vector<std::string>& friendsList);
void addSecretIngredient(std::vector<std::string>& myList, const std::string secretIngredient);

}  // namespace lasagna_master
