class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int>mnh;
        queue<int>q;
        vector<int> ans;
        map<int,int>mp;
        for(int i=0; i<k; i++){
            mnh.push(nums[i]);
            q.push(nums[i]);
            mp[nums[i]]++;
        }
        ans.push_back(mnh.top());
        for(int i=k; i<nums.size(); i++){
            mnh.push(nums[i]);
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            q.push(nums[i]);
            while(mp[mnh.top()]==0){
                mnh.pop();
            }
            ans.push_back(mnh.top());
            if(mnh.top()==q.front()){
                mnh.pop();
                q.pop();
            }
            else{
                q.pop();
            }
        }
        return ans;
    }
};