class Solution {
public:
    int countSubset(vector<int>& nums, int sum){
        int n = nums.size();
        int t[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(!i)t[i][j]=0;
                if(!j)t[i][j]=1;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1]<=j && nums[i-1]!= 0){
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[n][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum=0,zeroCount=0;
        if(nums.size()==1){
            if(nums[0]==abs(target))return 1;
            else return 0;
        }
        for(auto i:nums){
            totalSum += i;
            if(!i)zeroCount++;
        }
        int targetSum = (totalSum+target)/2;
        if(target > totalSum || (totalSum+target)%2 != 0)return 0;
        return countSubset(nums,targetSum)*pow(2,zeroCount);
    }
};