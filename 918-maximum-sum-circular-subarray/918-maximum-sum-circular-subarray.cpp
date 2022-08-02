class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums){
        int n = nums.size();
        int maxSum=INT_MIN;
        int minSum=INT_MAX;
        int totalSum=0;
        int tempMinSum=0;
        int tempMaxSum=0;
        for(int i=0; i<n; i++){
            totalSum += nums[i];
            tempMaxSum += nums[i];
            maxSum = max(tempMaxSum,maxSum);
            if(tempMaxSum<0)tempMaxSum=0;
            tempMinSum += nums[i];
            minSum = min(tempMinSum,minSum);
            if(tempMinSum>0)tempMinSum=0;
        }
        if(totalSum==minSum)return maxSum;
        return max(maxSum,totalSum-minSum);
    }
};