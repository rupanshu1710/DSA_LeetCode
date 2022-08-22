class Solution {
public:
    int t[10001];
    bool solve(vector<int>& nums, int indx){
        if(indx==nums.size()-1)return 1;
        if(nums[indx]==0)return 0;
        if(t[indx]!=-1)return t[indx];
        for(int i=indx+1; i<=nums[indx]+indx; i++){
            if(solve(nums,i))return t[indx] = 1;
        }
        return t[indx]= 0; 
    }
    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0);
    }
};