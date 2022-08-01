class Solution {
public:
    int t[10001];
    bool solve(vector<int>& nums, int idx){
        if(idx==nums.size()-1)return 1;
        if(t[idx]!=-1)return t[idx];
        if(nums[idx]==0)return t[idx] =  0;
        for(int i=idx+1; i<= idx + nums[idx]; i++){
            if(solve(nums,i)){
                return t[i] =  1;
            }
        }
        return t[idx] = 0;
    }
    bool canJump(vector<int>& nums) {
        for(int i= 0; i<10001; i++)t[i]=-1;
        return solve(nums,0);
    }
};