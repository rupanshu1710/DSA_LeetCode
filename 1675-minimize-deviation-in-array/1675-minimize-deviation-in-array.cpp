class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
       priority_queue<int>maxh;
        int n=nums.size();
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&1)
            {
                nums[i]*=2;
            }
            mini=min(mini,nums[i]);
            maxh.push(nums[i]);
        }
        int diff=INT_MAX;
        while(!maxh.empty())
        {
            int curr=maxh.top();
            maxh.pop();
            diff=min(diff,curr-mini);
            if(curr&1)break;
            curr/=2;
            maxh.push(curr);
            if(curr<mini)
            {
                mini=curr;
            }
        }
        return diff;
    }
};