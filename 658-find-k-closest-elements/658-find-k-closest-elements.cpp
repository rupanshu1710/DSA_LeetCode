class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        priority_queue<pair<int,int>>maxh;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            maxh.push({abs(nums[i]-x),nums[i]});
            if(maxh.size()>k)maxh.pop();
        }
        while(maxh.size()>0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};