#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <utility>

namespace queen_attack {
class chess_board {
   private:
    std::pair<int, int> w;
    std::pair<int, int> b;

   public:
    chess_board(std::pair<int, int> white, std::pair<int, int> black);
    std::pair<int, int> white() const;
    std::pair<int, int> black() const;
    bool can_attack() const;
};
}  // namespace queen_attack

#endif  // QUEEN_ATTACK_H