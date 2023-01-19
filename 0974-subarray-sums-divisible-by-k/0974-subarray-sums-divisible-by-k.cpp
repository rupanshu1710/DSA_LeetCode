class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int currSum=0;
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            currSum += nums[i];
            if(mp.find(currSum%k)!=mp.end())ans += mp[currSum%k];
            if(mp.find(k +(currSum)%k)!=mp.end())ans+=mp[k +(currSum)%k];
            if(currSum%k==0)ans++;
            if(currSum>=0)mp[abs(currSum%k)]++;
            else mp[k+(currSum%k)]++;
            // if(currSum%k==0)mp[currSum]++;
            cout<<ans<<endl;
        }
        return ans;
    }
};