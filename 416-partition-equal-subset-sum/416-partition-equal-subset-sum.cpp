class Solution {
public:
    int t[201][10001];
    bool isSubsetSum(vector<int>& nums, int targetSum)
    {
        for(int i=0; i<nums.size()+1; i++){
            for(int j=0; j<targetSum+1; j++){
                if(!i)t[i][j]=0;
                if(!j)t[i][j]=1;
            }
        }
        for(int i=1; i<nums.size()+1; i++){
            for(int j=1; j<targetSum+1; j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] or t[i-1][j];
                }
                else t[i][j] = t[i-1][j];
            }
        }
        return t[nums.size()][targetSum];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(auto i:nums){
            totalSum += i;
        }
        if(totalSum%2!=0){
            return false;
        }
        int targetSum = totalSum/2;
        return isSubsetSum(nums,targetSum);
    }
};