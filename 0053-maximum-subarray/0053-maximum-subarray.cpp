class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0;
        int ans = *min_element(nums.begin(),nums.end());
        if(*max_element(nums.begin(),nums.end())<0)return *max_element(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            currSum += nums[i];
            if(currSum<0){
                currSum=0;
            }
            ans = max(currSum,ans);
        }
        return ans;
    }
};