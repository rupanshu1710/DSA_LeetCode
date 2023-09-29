class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc = 1;
        bool dec = 1;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1]){
                dec = 0;
            }
            if(nums[i]<nums[i-1]){
                inc = 0;
            }
        }
        // return inc;
        return inc or dec;
    }
};