class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>fres ;
        int m = nums.size();
        int req ;
        for(int i = 0 ; i < m ; i++){
            req = target - nums[i];
            if(fres.find(req)!=fres.end()){
                return {fres[req] , i};
            }
            fres[nums[i]] = i;
        } return {};
    }
};