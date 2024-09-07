#include "pascals_triangle.h"

namespace pascals_triangle {
vector<vector<int>> generate_rows(int r) {
    vector<vector<int>> ans;
    for (int i = 1; i <= r; i++) {
        vector<int> row = {1};

        for (int j = 1; j < i - 1; j++) {
            int num = ans[i - 2][j - 1] + ans[i - 2][j];
            row.emplace_back(num);
        }

        if (i > 1) row.emplace_back(1);
        ans.emplace_back(row);
    }
    return ans;
}
}  // namespace pascals_triangle
