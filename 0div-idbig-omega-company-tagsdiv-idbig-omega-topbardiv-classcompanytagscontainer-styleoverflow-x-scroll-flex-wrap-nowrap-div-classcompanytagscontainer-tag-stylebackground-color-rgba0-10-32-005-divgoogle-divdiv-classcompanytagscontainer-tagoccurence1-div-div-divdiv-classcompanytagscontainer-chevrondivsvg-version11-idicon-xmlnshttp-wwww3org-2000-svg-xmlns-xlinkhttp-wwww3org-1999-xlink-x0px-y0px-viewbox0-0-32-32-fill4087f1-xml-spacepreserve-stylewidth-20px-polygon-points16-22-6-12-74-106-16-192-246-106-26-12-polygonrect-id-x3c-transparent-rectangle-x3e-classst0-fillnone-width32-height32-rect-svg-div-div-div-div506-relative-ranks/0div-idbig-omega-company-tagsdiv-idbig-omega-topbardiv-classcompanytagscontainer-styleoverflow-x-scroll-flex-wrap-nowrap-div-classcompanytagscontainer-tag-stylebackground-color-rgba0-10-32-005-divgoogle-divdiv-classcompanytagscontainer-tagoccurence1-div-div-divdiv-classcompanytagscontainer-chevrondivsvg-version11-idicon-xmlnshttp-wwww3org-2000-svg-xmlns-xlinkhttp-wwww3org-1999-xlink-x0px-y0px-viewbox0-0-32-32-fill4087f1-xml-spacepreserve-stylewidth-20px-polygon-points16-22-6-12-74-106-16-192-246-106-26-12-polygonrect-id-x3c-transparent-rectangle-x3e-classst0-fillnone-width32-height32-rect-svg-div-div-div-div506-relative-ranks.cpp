class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push({nums[i],i});
        }
        vector<string>ans(nums.size(),"");
        int count = 1;
        for(int i=0; i<nums.size();i++){
            if(count==1){
                ans[pq.top().second] = "Gold Medal";
                count++;
            }
            else if(count==2){
                ans[pq.top().second] = "Silver Medal"; 
                count++;
            }
            else if(count==3){
                ans[pq.top().second] = "Bronze Medal"; 
                count++;
            }
            else{
                ans[pq.top().second] = to_string(count);
                count++;
            }
            pq.pop();
        }
        return ans;
    }
};