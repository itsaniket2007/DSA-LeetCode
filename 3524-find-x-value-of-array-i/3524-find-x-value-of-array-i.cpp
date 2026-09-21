class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k), prev(k);
        for (int x : nums) {
            vector<long long> curr(k);
            curr[x % k]++;
            for (int r = 0; r < k; ++r) if (prev[r]) curr[(r * (x % k)) % k] += prev[r];
            for (int r = 0; r < k; ++r) res[r] += curr[r];
            prev = move(curr);
        }
        return res;
    }
};