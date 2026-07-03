#include <vector>
#include <algorithm>

class Solution {
private:
    bool canMakeBouquets(const std::vector<int>& bloomDay, int m, int k, int days) {
        int bouquets = 0;
        int flowers = 0;
        
        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0; 
                }
            } else {
                flowers = 0; 
            }
            if (bouquets >= m) {
                return true;
            }
        }
        
        return bouquets >= m;
    }

public:
    int minDays(std::vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }
        int low = 1;
        int high = *std::max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (canMakeBouquets(bloomDay, m, k, mid)) {
                ans = mid;       
                high = mid - 1;
            } else {
                low = mid + 1;   
            }
        }
        
        return ans;
    }
};