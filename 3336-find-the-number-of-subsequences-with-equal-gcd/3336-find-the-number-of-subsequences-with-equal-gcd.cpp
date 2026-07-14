#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int max_val = 200;
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(max_val + 1, vector<int>(max_val + 1, 0));
        dp[0][0] = 1;
        for (int num : nums) {
            vector<vector<int>> next_dp = dp;
            for (int x = 0; x <= max_val; ++x) {
                for (int y = 0; y <= max_val; ++y) {
                    if (dp[x][y] == 0) continue;
                    int next_x = (x == 0) ? num : std::gcd(x, num);
                    next_dp[next_x][y] = (next_dp[next_x][y] + dp[x][y]) % MOD;
                    int next_y = (y == 0) ? num : std::gcd(y, num);
                    next_dp[x][next_y] = (next_dp[x][next_y] + dp[x][y]) % MOD;
                }
            }
            dp = next_dp;
        }
        int ans = 0;
        for (int g = 1; g <= max_val; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }
        return ans;
    }
};