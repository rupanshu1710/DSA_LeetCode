class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i=0,j=1,n=nums.size(),ans=0;
        while(j<n){
            if(nums[j]>nums[j-1]){
                j++;
            }
            else{
                ans = max(j-i,ans);
                i = j;
                j++;
            }
        }
        ans = max(j-i,ans);
        reverse(nums.begin(),nums.end());
        i=0,j=1;
        while(j<n){
            if(nums[j]>nums[j-1]){
                j++;
            }
            else{
                ans = max(j-i,ans);
                i = j;
                j++;
            }
        }
        ans = max(j-i,ans);
        return ans;
    }
};