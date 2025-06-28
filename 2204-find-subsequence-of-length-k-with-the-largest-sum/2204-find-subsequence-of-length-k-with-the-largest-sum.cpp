class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int>temp = nums;
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int n = nums.size();
        vector<int>ans ;
        for(int i=n-1; i>=n-k; i--){
            mp[nums[i]]++;
        }
        for(int i=0; i<n; i++){
            if(mp[temp[i]]>0){
                ans.push_back(temp[i]);
                mp[temp[i]]--;
            }
        }
        return ans;
    }
};