#include <vector>

using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalXor = 0;
        bool allZeros = true;
        for (int num : nums) {
            totalXor ^= num;
            if (num != 0) {
                allZeros = false;
            }
        }
        if (allZeros) {
            return 0;
        }
        if (totalXor != 0) {
            return n;
        }
        return n - 1;
    }
};