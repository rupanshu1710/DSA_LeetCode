class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int sum1 = 0;
        int sum2 = 0;
        int n = nums1.size();
        for(auto i:nums1){
            sum1 += i;
        }
        for(auto i:nums2){
            sum2 += i;
        }
        return (sum2-sum1)/n;
    }
};