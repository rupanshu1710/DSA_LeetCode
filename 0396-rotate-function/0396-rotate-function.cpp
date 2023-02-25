class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int ans = 0;
        int k = 0;
        int sum = 0;
        for(auto i:nums){
            ans += k*i;
            k++;
            sum += i;
        }
        k=1;
        int temp = ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            cout<<temp<<" ";
            temp = temp +sum - nums[n-i-1]*(n);
            ans = max(ans,temp);
        }
        return ans;
    }
};