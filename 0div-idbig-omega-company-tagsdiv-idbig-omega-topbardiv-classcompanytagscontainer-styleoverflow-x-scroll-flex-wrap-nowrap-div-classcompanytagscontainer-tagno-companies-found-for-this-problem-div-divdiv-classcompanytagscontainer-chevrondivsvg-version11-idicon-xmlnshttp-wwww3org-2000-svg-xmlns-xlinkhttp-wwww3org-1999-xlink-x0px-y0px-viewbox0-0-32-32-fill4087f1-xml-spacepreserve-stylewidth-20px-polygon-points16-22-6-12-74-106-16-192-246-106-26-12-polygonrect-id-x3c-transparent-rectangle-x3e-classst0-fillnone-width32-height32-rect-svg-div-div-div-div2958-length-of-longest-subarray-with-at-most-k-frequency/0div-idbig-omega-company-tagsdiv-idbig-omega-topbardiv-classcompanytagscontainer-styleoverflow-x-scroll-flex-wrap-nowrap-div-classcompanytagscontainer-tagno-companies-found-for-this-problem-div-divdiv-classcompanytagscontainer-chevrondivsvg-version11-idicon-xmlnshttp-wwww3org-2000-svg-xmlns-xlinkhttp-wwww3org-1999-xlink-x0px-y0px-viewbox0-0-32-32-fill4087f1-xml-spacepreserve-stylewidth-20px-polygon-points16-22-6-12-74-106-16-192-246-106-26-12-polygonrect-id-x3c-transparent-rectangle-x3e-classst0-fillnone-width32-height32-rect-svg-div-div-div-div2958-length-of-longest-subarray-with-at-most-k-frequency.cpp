class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        vector<int>temp1;
        vector<int>temp2;
        int x = -1;
        int ans = 0;
        map<int,int>mp;
        int i=0,j=0;
        int n = nums.size();
        while(j<n){
            // cout<<i<<" "<<j<<endl;
            mp[nums[j]]++;
            if(mp[nums[j]]<=k){
                ans = max(ans,j-i+1);
            }
            while(mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};