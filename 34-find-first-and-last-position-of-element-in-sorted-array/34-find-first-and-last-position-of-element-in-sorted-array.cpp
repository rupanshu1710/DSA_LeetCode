class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int start=0; 
        int end=n-1;
        int last=-1;
        int first=-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                while(mid<n && nums[mid]==target)mid++;
                last = mid-1;
                break;
            }
            else if(nums[mid]>target)end = mid-1;
            else start = mid+1;
        }
        if(last==-1)return {-1,-1};
        start=0; 
        end=n-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(nums[mid]==target){
                while(mid>=0 && nums[mid]==target)mid--;
                first = mid+1;
                break;
            }
            else if(nums[mid]>target)end = mid-1;
            else start = mid+1;
        }
        return {first,last};
    }
};