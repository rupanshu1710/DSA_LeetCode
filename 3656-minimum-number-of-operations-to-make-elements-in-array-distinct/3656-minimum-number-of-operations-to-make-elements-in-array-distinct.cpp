class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       map<int,int>mp;
       for(auto i:nums){
        mp[i]++;
       } 
       int n = nums.size();
       int ans=0;
       int i=0;
       while(nums.size()!=mp.size()){
        ans++;
        mp[nums[i]]--;
        if(mp[nums[i]]==0)mp.erase(nums[i]);
        nums.erase(nums.begin()+i);
        if(i<nums.size()){
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            nums.erase(nums.begin()+i);

        }
        if(i<nums.size()){
            mp[nums[i]]--;
            if(mp[nums[i]]==0)mp.erase(nums[i]);
            nums.erase(nums.begin()+i);
        }
        // n -= 3;

       }
       return ans;
    }
};;