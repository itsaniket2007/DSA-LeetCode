#include <vector>
#include <numeric>
#include <algorithm>
class Solution {
public:
    bool canShip(const std::vector<int>& weights, int days, int capacity) {
        int currentDays = 1;
        int currentLoad = 0;
        for (int weight : weights) {
            if (weight > capacity) return false;
            if (currentLoad + weight > capacity) {
                currentDays++;
                currentLoad = weight;
                if (currentDays > days) return false;
            } else {
                currentLoad += weight;
            }
        }
        return true;
    }
    int shipWithinDays(std::vector<int>& weights, int days) {
        int low = *std::max_element(weights.begin(), weights.end());
        int high = std::accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid)) {
                ans = mid;     
                high = mid - 1;
            } else {
                low = mid + 1;  
            }
        }
        return ans;
    }
};