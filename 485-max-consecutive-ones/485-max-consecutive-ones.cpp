class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=INT_MIN,count=0;
        for(auto i:nums){
            if(i==1)count++;
            else count=0;
            ans = max(count,ans);
        }
        return ans;
    }
};