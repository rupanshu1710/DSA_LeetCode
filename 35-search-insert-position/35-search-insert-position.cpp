class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int ans = 0;
        int end = n;
        while(start<end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
        }
        return end;
        
        
    }
};