class Solution {
public:
    bool check(vector<int>& nums, int mid){
        long long temp=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=mid){
                temp += mid-nums[i];
            }
            else{
                if(nums[i]>mid+temp)return 0;
                else temp -= nums[i]-mid; 
            }
        }
        return 1;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(nums,mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};