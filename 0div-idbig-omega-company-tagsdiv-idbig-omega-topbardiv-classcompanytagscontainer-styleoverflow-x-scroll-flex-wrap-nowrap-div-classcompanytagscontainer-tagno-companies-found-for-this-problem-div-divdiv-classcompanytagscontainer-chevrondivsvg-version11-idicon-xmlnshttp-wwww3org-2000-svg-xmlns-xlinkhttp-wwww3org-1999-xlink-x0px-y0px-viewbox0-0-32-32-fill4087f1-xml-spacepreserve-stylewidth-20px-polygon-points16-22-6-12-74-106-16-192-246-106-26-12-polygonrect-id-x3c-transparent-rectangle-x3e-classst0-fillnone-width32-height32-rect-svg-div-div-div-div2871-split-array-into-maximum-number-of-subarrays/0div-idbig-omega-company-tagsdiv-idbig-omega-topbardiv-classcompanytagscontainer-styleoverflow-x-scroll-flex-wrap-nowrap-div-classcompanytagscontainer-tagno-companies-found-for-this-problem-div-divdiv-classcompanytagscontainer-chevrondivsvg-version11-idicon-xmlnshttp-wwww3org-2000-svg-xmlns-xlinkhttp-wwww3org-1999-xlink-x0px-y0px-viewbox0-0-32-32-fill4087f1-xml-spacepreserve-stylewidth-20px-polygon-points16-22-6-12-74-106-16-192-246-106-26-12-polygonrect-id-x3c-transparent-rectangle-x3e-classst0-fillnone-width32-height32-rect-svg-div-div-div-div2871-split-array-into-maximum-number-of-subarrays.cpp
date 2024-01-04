class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int temp = nums[0],n=nums.size();
        for(int i=1; i<n; i++){
            temp &= nums[i]; 
        }
        int ans=1;
        vector<int>right(n);
        long long a=nums[0];
        a = 2097151;
        for(int i=n-1; i>=0; i--){
            a &= nums[i];
            right[i] = a;
        }
        cout<<temp<<endl;
        a = 2097151;
        for(int i=0; i<n-1; i++){
            a &= (long long)nums[i];
            if((a+right[i+1])==temp){
                ans++;
                a = 2097151;
            }
        }
        return ans;
    }
};