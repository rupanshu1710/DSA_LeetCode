class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto i:nums){
            st.insert(i);
        }
        int ans=0;
        for(int i=0; i<nums.size(); i++){
            if(st.count(nums[i]-1)==0){
                int index = i;
                int cnt = 1;
                while(st.count(nums[index]+1)!=0){
                    nums[index]++;
                    cnt++;
                }
                
            ans = max(ans,cnt);
            }
        }
        return ans;
    }
};