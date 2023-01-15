class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n = nums.size();
        long long ans=0;
        map<long long,long long>mp;
        long long cnt=0;
        long long i=0,j=0;
        while(j<nums.size()){
            if(mp.find(nums[j])!=mp.end())cnt+=(mp[nums[j]]);
            mp[nums[j]]++;
            if(cnt<k)j++;
            if(cnt>=k){
                while(cnt>=k){
                    if(mp[nums[i]]>0){
                        cnt -= (mp[nums[i]] -1);
                        mp[nums[i]]--;
                        if(mp[nums[i]]==0)mp.erase(nums[i]);
                        cout<<i<<" "<<j<<endl;
                        ans += n-j;
                        cout<<ans<<endl;
                        i++;
                    }
                }
                    j++;
            }
        }
        // ans = n*(n+1)/2 - ans;
        return ans;
    }
};