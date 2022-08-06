class Solution {
public:
    int t[1001];
    int solve(vector<int>& nums, int target){
        if(target==0)return 1;
        if(target<0)return 0;
        if(t[target]!=-1)return t[target];
        int ans=0;
        for(auto i:nums){
            ans += solve(nums, target-i);
        }
        return t[target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target){
        memset(t,-1,sizeof(t));
        return solve(nums,target);
    }
};