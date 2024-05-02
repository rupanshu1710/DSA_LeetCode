class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1,n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(int i=0; i<n; i++){
            if(nums[i]>ans && mp.find(-1*(abs(nums[i])))!=mp.end())ans = nums[i];
        }
        return ans;
    }
};