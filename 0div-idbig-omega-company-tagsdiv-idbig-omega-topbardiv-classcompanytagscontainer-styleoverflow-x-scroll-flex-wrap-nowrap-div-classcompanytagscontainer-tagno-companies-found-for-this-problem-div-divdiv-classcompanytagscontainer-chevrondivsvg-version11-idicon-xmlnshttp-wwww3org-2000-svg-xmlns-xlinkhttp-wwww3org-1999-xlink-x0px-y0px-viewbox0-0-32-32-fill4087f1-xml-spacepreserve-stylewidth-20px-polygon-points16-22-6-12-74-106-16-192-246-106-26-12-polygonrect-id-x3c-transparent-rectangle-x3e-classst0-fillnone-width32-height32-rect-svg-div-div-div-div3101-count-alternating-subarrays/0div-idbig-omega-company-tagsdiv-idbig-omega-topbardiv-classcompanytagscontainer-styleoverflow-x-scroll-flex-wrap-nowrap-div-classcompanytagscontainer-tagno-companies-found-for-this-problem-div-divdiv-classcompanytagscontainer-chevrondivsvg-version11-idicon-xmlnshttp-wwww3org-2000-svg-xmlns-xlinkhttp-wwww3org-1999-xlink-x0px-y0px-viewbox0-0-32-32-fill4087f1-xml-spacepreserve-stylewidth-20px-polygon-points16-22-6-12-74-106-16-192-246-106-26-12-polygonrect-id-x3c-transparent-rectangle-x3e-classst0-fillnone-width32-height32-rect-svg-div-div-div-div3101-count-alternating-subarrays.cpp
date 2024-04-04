class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans=0;
        vector<int> temp;
        long long cnt=0,x,j=1,i=0,n=nums.size();
        while(j<n){
            if(nums[j]!=nums[j-1])j++;
            else{
                x = j-1;
                while(j<n && nums[j]==nums[j-1])j++;
                x = x - i+1;
                ans += x*(x+1)/2;
                ans -= x;
                i = j-1;
                
            }
            // cout<<ans<<endl;
        }
        x = j-i;
        ans += x*(x+1)/2;
        ans -= x;
        return ans+n;
    }
};