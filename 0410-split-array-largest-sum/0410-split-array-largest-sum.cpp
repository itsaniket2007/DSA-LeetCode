#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int count = 1;
            int sum = 0;

            for (int num : nums) {

                if (sum + num <= mid) {
                    sum += num;
                }
                else {
                    count++;
                    sum = num;
                }
            }

            if (count <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};