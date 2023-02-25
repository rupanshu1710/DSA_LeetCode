class Solution {
public:
    vector<int> a;
    map<int,vector<int>>mp;
    Solution(vector<int>& nums) {
        a = nums;
        for(int i=0; i<a.size(); i++){
            mp[a[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        if(mp.find(target)!=mp.end()){
            if(mp.size()==1)return mp[target][0];
            vector<int>temp = mp[target];
            int ans = mp[target][0];
            vector<int>temp1;
            for(int i=1; i<temp.size(); i++){
                temp1.push_back(temp[i]);
            }
            temp1.push_back(temp[0]);
            mp[target] = temp1;
            return ans;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */