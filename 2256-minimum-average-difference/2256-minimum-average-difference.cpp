class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        long long sum=0; 
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int ans = 0;
        int temp = INT_MAX;
        long long currSum=0;
        for(int i=0; i<n-1; i++){
            currSum += nums[i];
            if(abs((currSum/(i+1)) - ((sum-currSum)/(n-i-1)))<temp){
                ans = i;
                temp = abs((currSum/(i+1)) - ((sum-currSum)/(n-i-1)));
                // cout<<temp<<endl;
            }
        }
        currSum += nums[n-1];
        if(temp> (abs((currSum/(n))))){
            ans = n-1;
        }
        return  ans;
    }
};