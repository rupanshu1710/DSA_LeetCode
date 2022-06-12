class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int left = 0;
        int right = 0;
        int currSum=0;
        int n = nums.size();
        int ans = 0;
        while(right<n){
            if(mpp.find(nums[right])!=mpp.end()){
                for(int i=left; i<max(left,mpp[nums[right]]+1); i++){
                    currSum -= nums[i];
                }
                left = max(left,mpp[nums[right]]+1);
            }
            currSum += nums[right];
            mpp[nums[right]] = right;
            ans = max(currSum,ans);
            right++;
        }
        return ans;
    }
};