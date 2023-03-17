class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        map<long long,long long>mp;
        long long ans=0;
        long long xr = 0;
        for(int i=0; i<nums.size(); i++){
            xr ^= nums[i];
            if(xr==0)ans++;
            ans += mp[xr^0];
            mp[xr]++;
        }
        return ans;
    }
};