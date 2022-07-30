class Solution {
public:
    int t[101];
    int solve(vector<int>& nums, int idx){
        if(idx==nums.size())return t[idx]=0;
        if(idx==nums.size()-1)return t[idx]=nums[idx];
        if(t[idx]!=-1)return t[idx];
        return t[idx] = max((nums[idx] + solve(nums,idx+2)), solve(nums,idx+1));
    }
    int rob(vector<int>& nums) {
        for(int i=0; i<101; i++)t[i]=-1;
        return max(solve(nums,0),solve(nums,1));
    }
};