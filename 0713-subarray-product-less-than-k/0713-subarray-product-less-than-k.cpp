class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int t) {
        if(t==0)return 0;
        long long prod = 1;
        int i=0,j=0,ans=0,count=0,k=1;
        while(j<nums.size()){
            prod *= nums[j];
            if(nums[j]<t)count++;
            if(prod<t){
                j++;
            }
            else{
                while(prod>=t){
                    prod /= nums[i];
                    ans += j-i;
                    i++;
                }
                j++;
            }
        }
        ans += (j-i)*(j-i+1)/2;
        if(count==0)return 0;
        return ans;
    }
};