class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        int ans = INT_MAX;
        for(auto i:nums1){
            mp[i]++;
        }
        for(int i=0; i<nums2.size(); i++){
            if(mp.find(nums2[i])!=mp.end()){
                ans = min(ans,nums2[i]);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};