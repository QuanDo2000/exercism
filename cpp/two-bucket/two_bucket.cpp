#include "two_bucket.h"

#include <queue>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

namespace two_bucket {
pair<int, int> pour(int from, int to, int to_cap) {
    // From b1 to b2
    if (to == to_cap || from == 0) return {from, to};
    if (from >= to_cap - to) return {from - (to_cap - to), to_cap};
    return {0, to + from};
}

pair<int, int> pourr(int from, int to, int to_cap) {
    pair<int, int> p = pour(from, to, to_cap);
    return {p.second, p.first};
}

measure_result measure(int b1_cap, int b2_cap, int target, bucket_id start) {
    vector<vector<int>> moves(b1_cap + 1, vector<int>(b2_cap + 1, 0));
    queue<pair<int, int>> q;
    if (start == bucket_id::one) {
        q.push({b1_cap, 0});
        moves[b1_cap][0] = 1;
        moves[0][b2_cap] = -1;
    } else {
        q.push({0, b2_cap});
        moves[0][b2_cap] = 1;
        moves[b1_cap][0] = -1;
    }

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        int curr_move = moves[curr.first][curr.second];
        if (curr_move == -1) continue;
        if (curr.first == target) {
            return {curr_move, bucket_id::one, curr.second};
        }
        if (curr.second == target) {
            return {curr_move, bucket_id::two, curr.first};
        }

        vector<pair<int, int>> nexts = {
            pour(curr.first, curr.second, b2_cap),
            pourr(curr.second, curr.first, b1_cap),
            {0, curr.second},
            {curr.first, 0},
            {b1_cap, curr.second},
            {curr.first, b2_cap},
        };
        for (auto next : nexts) {
            if (moves[next.first][next.second] == 0) {
                moves[next.first][next.second] = curr_move + 1;
                q.push(next);
            }
        }
    }
    throw runtime_error("no possible path");
}
}  // namespace two_bucket
