#if !defined(FOOD_CHAIN_H)
#define FOOD_CHAIN_H

#include <string>
#include <vector>

using namespace std;

namespace food_chain {
string verse(size_t num);
string verses(size_t start_idx, size_t end_idx);
string sing();
}  // namespace food_chain

#endif  // FOOD_CHAIN_H