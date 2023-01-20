class Solution {
public:
    void getAns(vector<int>& nums, int idx, vector<int>& temp, vector<vector<int>>& ans){
        if(idx>nums.size()-1)return;
        if(temp.size()>0){
            if(temp.back()<=nums[idx]){
                vector<int>temp1 = temp;
                vector<int>temp2 = temp;
                temp1.push_back(nums[idx]);
                ans.push_back(temp1);
                ans.push_back(temp2);
                getAns(nums,idx+1,temp1,ans);
                getAns(nums,idx+1,temp2,ans);
            }
            else{
                ans.push_back(temp);
                getAns(nums,idx+1,temp,ans);
            }
        }
        else{
            vector<int>temp1 = temp;
            vector<int>temp2 = temp;
            temp1.push_back(nums[idx]);
            ans.push_back(temp1);
            ans.push_back(temp2);
            getAns(nums,idx+1,temp1,ans);
            getAns(nums,idx+1,temp2,ans);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        getAns(nums,0,temp,ans);
        set<vector<int>>st;
        for(auto i:ans){
            if(i.size()>1){
                st.insert(i);
            }
        }
        vector<vector<int>>res;
        for(auto i:st){
            res.push_back(i);
        }
        return res;
    }
};