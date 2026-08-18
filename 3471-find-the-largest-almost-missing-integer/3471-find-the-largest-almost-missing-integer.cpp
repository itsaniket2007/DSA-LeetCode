class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1) {
            unordered_map<int, int> count;
            for (int x : nums) {
                count[x]++;
            }
            int ans = -1;
            for (auto& [val, freq] : count) {
                if (freq == 1) {
                    ans = max(ans, val);
                }
            }
            return ans;
        }
        if (k == n) {
            int max_val = -1;
            for (int x : nums) {
                max_val = max(max_val, x);
            }
            return max_val;
        }
        bool count0 = false, countN = false;
        for (int i = 0; i < n; i++) {
            if (nums[i] == nums[0]) count0 = true;
            if (nums[i] == nums[n - 1]) countN = true;
        }
        int freq0 = 0, freqN = 0;
        for (int x : nums) {
            if (x == nums[0]) freq0++;
            if (x == nums[n - 1]) freqN++;
        }
        int ans = -1;
        if (freq0 == 1) {
            ans = max(ans, nums[0]);
        }
        if (freqN == 1) {
            ans = max(ans, nums[n - 1]);
        }
        return ans;
    }
};