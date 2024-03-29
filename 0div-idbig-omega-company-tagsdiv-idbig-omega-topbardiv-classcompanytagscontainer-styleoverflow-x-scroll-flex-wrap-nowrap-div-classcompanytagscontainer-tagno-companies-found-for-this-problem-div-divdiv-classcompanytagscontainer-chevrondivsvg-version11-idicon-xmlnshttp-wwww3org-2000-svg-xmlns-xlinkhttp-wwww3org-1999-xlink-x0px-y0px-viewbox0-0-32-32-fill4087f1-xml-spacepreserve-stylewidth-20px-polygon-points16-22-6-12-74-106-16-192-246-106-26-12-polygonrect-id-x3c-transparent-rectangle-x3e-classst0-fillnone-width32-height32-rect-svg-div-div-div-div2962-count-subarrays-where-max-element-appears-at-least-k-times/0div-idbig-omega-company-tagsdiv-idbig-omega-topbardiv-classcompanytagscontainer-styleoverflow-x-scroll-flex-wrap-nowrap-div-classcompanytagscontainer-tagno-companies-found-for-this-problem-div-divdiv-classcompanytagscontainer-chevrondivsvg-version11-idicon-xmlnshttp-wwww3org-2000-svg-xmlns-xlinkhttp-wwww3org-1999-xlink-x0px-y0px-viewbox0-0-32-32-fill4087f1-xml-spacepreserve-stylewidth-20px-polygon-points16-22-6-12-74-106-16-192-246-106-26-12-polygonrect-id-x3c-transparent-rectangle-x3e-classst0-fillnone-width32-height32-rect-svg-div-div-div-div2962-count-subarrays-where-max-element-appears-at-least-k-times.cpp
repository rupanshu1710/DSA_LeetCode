class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        long long ans=0;
        int cnt=0; 
        int i=0,j=0;
        while(j<n){
            cnt+=(nums[j]==mx);
            while(i<=j && cnt>=k){
                ans+=(n-j);
                cnt-=(nums[i] == mx);
                i++;
            }
            j++;
        }
        
        return ans;
    }
};
