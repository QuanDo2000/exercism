#include "spiral_matrix.h"

namespace spiral_matrix {
vector<vector<uint32_t>> spiral_matrix(int size) {
    vector<int> dir_x = {0, 1, 0, -1};
    vector<int> dir_y = {1, 0, -1, 0};

    int dir = 0, i = 0, j = 0;
    uint32_t num = 1;
    vector<vector<uint32_t>> matrix(size, vector<uint32_t>(size));
    while (num <= size * size) {
        matrix[i][j] = num++;

        int ni = i + dir_x[dir];
        int nj = j + dir_y[dir];
        if (ni >= size || ni < 0 || nj >= size || nj < 0 || matrix[ni][nj] != 0) {
            dir = (dir + 1) % dir_x.size();
            ni = i + dir_x[dir];
            nj = j + dir_y[dir];
        }
        i = ni;
        j = nj;
    }
    return matrix;
}
}  // namespace spiral_matrix
