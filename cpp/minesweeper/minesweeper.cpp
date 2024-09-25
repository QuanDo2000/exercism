#include "minesweeper.h"

namespace minesweeper {
const char MINE = '*';

char annotate_at(vector<string> board, int i, int j) {
    if (board[i][j] == MINE) return board[i][j];
    int count = 0;
    vector<int> dir = {0, 1, -1};
    for (int dirx : dir) {
        for (int diry : dir) {
            int new_x = i + dirx;
            int new_y = j + diry;
            if (new_x < 0 || new_x >= (int)board.size()) continue;
            if (new_y < 0 || new_y >= (int)board[i].size()) continue;
            if (board[new_x][new_y] == MINE) count++;
        }
    }
    if (count == 0)
        return ' ';
    else
        return '0' + count;
}

vector<string> annotate(vector<string> board) {
    vector<string> ans;
    for (size_t i = 0; i < board.size(); i++) {
        string line = board[i];
        string new_line = "";
        for (size_t j = 0; j < line.size(); j++) {
            new_line += annotate_at(board, i, j);
        }
        ans.emplace_back(new_line);
    }
    return ans;
}
}  // namespace minesweeper
