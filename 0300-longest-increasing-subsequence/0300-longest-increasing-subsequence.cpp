class Solution {
public:
    int t[2501][2501];
    int solve(vector<int>& nums,int idx, int prev){
        if(idx>nums.size()-1)return 0;
        if(t[idx][prev+1]!=-1)return t[idx][prev+1];
        if(prev==-1 || nums[idx]>nums[prev]){
            return t[idx][prev+1] = max(1+solve(nums,idx+1,idx),solve(nums,idx+1,prev));
        }
        else return t[idx][prev+1] = solve(nums,idx+1,prev);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,-1);
    }
};