class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=-1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
                i--;
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]!=i+1)return nums[i];
        }
        return ans;
    }
};