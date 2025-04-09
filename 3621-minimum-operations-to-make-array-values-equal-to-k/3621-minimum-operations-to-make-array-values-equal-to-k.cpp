class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int mn = *min_element(nums.begin(),nums.end());
        if(mn<k)return -1;
        for(auto i:mp){
            int a = i.first;
            if(a>k)ans++;
        }
        return ans;
    }
};