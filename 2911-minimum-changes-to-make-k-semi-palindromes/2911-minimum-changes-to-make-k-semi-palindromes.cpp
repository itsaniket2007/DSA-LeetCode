#include <string>
#include <vector>
#include <algorithm>
#include <climits>
class Solution {
public:
    int getPalindromeChanges(const std::string& s, int start, int end) {
        int changes = 0;
        while (start < end) {
            if (s[start] != s[end]) {
                changes++;
            }
            start++;
            end--;
        }
        return changes;
    }
    int minimumChanges(std::string s, int k) {
        int n = s.length();
        std::vector<std::vector<int>> cost(n, std::vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = j - i + 1;
                int min_changes = 1e9;
                for (int d = 1; d < len; ++d) {
                    if (len % d == 0) {
                        int current_changes = 0;
                        for (int offset = 0; offset < d; ++offset) {
                            std::string group = "";
                            for (int p = i + offset; p <= j; p += d) {
                                group += s[p];
                            }
                            current_changes += getPalindromeChanges(group, 0, group.length() - 1);
                        }
                        min_changes = std::min(min_changes, current_changes);
                    }
                }
                cost[i][j] = min_changes;
            }
        }
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 1e9));
        dp[0][0] = 0;

        for (int j = 1; j <= k; ++j) {
            for (int i = 1; i <= n; ++i) {
                for (int prev = (j - 1) * 2; prev < i; ++prev) {
                    if (dp[prev][j - 1] != 1e9 && cost[prev][i - 1] != 1e9) {
                        dp[i][j] = std::min(dp[i][j], dp[prev][j - 1] + cost[prev][i - 1]);
                    }
                }
            }
        }

        return dp[n][k];
    }
};