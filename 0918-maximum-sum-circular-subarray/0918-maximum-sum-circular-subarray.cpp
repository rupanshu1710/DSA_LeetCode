class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int>temp;
        long long sum=0;
        bool flag=0,flag2=0;
        for(auto i:nums){
            temp.push_back(i);
            sum += i;
            if(i<0)flag=1;
            else flag2=1;
        }
        int currSum=0,maxSum=INT_MIN;
        for(int i=0; i<temp.size(); i++){
            currSum += temp[i];
            maxSum = max(currSum,maxSum);
            if(currSum<0){
                currSum=0;
            }
        }
        currSum=0;
        int minSum=INT_MAX;
        for(int i=0; i<temp.size(); i++){
            currSum += temp[i];
            minSum = min(currSum,minSum);
            if(currSum>0){
                currSum=0;
            }
        }
        if(flag2)return max(((int)sum - minSum), maxSum);
        else return maxSum;
    }
};