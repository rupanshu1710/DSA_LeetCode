class Solution {
public:
    int t[2501][2501];
    int lengthOfLIS(vector<int>& nums) {
        memset(t,0,sizeof(t));
        for(int i=nums.size()-1; i>=0; i--){
            for(int j=i-1; j>=-1; j--){
                if(j==-1||nums[i]>nums[j])t[i][j+1] = max(1+t[i+1][i+1], t[i+1][j+1]);
                else t[i][j+1]=t[i+1][j+1];
            }
        }
        return t[0][0];
    }
};