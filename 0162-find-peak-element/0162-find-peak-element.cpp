class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int m = nums.size();
        int low = 0;
        int high = m - 1;
        int peak = 0 ;
        while(low<high){
            int mid = low + (high - low) / 2;
            if(nums[mid]>nums[mid+1]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        } return low;
    }
};