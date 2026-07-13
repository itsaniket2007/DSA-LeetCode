#include <vector>
#include <algorithm>
#include <cmath>
class Solution {
private:
    bool isValidDivisor(const std::vector<int>& nums, int divisor, int threshold) {
        long long currentSum = 0;
        for (int num : nums) {
            currentSum += (num + divisor - 1) / divisor;
            if (currentSum > threshold) {
                return false;
            }
        }
        return currentSum <= threshold;
    }
public:
    int smallestDivisor(std::vector<int>& nums, int threshold) {
        int low = 1;
        int high = *std::max_element(nums.begin(), nums.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isValidDivisor(nums, mid, threshold)) {
                ans = mid;       
                high = mid - 1; 
            } else {
                low = mid + 1;    
            }
        }
        return ans;
    }
};