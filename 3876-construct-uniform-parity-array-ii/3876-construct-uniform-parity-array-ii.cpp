#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    bool uniformArray(std::vector<int>& nums1) {
        int min_odd = INT_MAX;
        for (int x : nums1) {
            if (x % 2 != 0) {
                min_odd = std::min(min_odd, x);
            }
        }
        auto check = [&](int target_parity) {
            for (int x : nums1) {
                if (x % 2 != target_parity) {
                    if (min_odd == INT_MAX || x <= min_odd) {
                        return false;
                    }
                }
            }
            return true;
        };
        return check(0) || check(1);
    }
};