class Solution {
public:
    int t[201][10001];
    bool isSubsetSum(vector<int>& nums, int targetSum, int index)
    {
        if(index==nums.size()){
            if(targetSum==0)return true;
            else return false;
        }
        if(targetSum==0)return true;
        if(t[index][targetSum]!=-1)return t[index][targetSum];
        else{
            if(nums[index]<=targetSum){
                return t[index][targetSum] = isSubsetSum(nums,targetSum-nums[index],index+1) or isSubsetSum(nums,targetSum,index+1);
            }
            else return t[index][targetSum] = isSubsetSum(nums,targetSum,index+1);
        }
        return t[index][targetSum];
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
        memset(t,-1,sizeof(t));
        return isSubsetSum(nums,targetSum,0);
    }
};