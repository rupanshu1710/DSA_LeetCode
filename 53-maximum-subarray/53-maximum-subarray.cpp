class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> t(nums.size());
        int currSum=nums[0];
        t[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(currSum<0)currSum=0;
            currSum += nums[i];
            t[i] = max(t[i-1],currSum);
        }
        return t[nums.size()-1];
    }
};