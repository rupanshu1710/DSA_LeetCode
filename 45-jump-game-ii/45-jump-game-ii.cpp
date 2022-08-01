class Solution {
public:
    int t[10001];
    long long int solve(vector<int>& nums, int idx){
        if(idx>=nums.size()-1)return 0;
        if(t[idx]!=-1)return t[idx];
        long long int ans = INT_MAX;
        for(int i=idx+1; i<= idx + nums[idx]; i++){
            ans = min(1+solve(nums,i),ans);
        }
        return t[idx] = ans;
    }
    int jump(vector<int>& nums){
        memset(t,-1,sizeof(t));
        return solve(nums,0);
    }
};