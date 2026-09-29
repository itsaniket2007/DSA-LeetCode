#include <vector>
#include <string.h>

class Solution {
    int m, n;
    int memo[100][100][201];
    bool dfs(int i, int j, int count, const std::vector<std::vector<char>>& grid) {
        if (grid[i][j] == '(') {
            count++;
        } else {
            count--;
        }
        if (count < 0) return false;
        if (i == m - 1 && j == n - 1) {
            return count == 0;
        }
        if (memo[i][j][count] != -1) {
            return memo[i][j][count];
        }
        bool res = false;
        if (i + 1 < m) {
            res = res || dfs(i + 1, j, count, grid);
        }
        if (!res && j + 1 < n) {
            res = res || dfs(i, j + 1, count, grid);
        }
        return memo[i][j][count] = res;
    }
public:
    bool hasValidPath(std::vector<std::vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;
        memset(memo, -1, sizeof(memo));
        return dfs(0, 0, 0, grid);
    }
};