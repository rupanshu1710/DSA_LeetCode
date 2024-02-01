class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int i=0,j=2;
        while(j<nums.size()){
            vector<int> temp;
            if(nums[j]-nums[i]<= k){
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
                ans.push_back(temp);
                i+=3;
                j+=3;
            }
            else return {};
        }
        return ans;
    }
};