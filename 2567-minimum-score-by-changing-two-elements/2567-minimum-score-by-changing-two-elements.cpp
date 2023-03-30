class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> temp = nums;
        temp[n-1] = temp[n-2];
        temp[0] = temp[n-1];
        sort(temp.begin(),temp.end());
        ans = min(temp.back()-temp[0],ans);
        temp = nums;
        temp[0] = temp[1];
        temp[n-1] = temp[0];
        sort(temp.begin(),temp.end());
        ans = min(temp.back()-temp[0],ans);
        temp = nums;
        temp[0] = temp[1];
        temp[n-1] = temp[n-2];
        sort(temp.begin(),temp.end());
        ans = min(temp.back()-temp[0],ans);
        temp = nums;
        temp[0] = temp[1] = temp[2];
        sort(temp.begin(),temp.end());
        ans = min(temp.back()-temp[0],ans);
        temp = nums;
        temp[n-1] = temp[n-2] = temp[n-3];
        sort(temp.begin(),temp.end());
        ans = min(temp.back()-temp[0],ans);
        return ans;
    }
};