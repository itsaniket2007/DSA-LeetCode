#include <vector>
#include <algorithm>

class Solution {
private:
    bool canEatAll(const std::vector<int>& piles, int h, int k) {
        long long totalHours = 0; 
        for (int pile : piles) {
            totalHours += (pile + k - 1) / k;
            if (totalHours > h) {
                return false;
            }
        }
        return totalHours <= h;
    }
public:
    int minEatingSpeed(std::vector<int>& piles, int h) {
        int low = 1;
        int high = *std::max_element(piles.begin(), piles.end());
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canEatAll(piles, h, mid)) {
                ans = mid;      
                high = mid - 1;   
            } else {
                low = mid + 1;   
            }
        }
        return ans;
    }
};