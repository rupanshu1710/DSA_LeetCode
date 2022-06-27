class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>>maxh;
        for(auto i:points){
            maxh.push({i[0]*i[0] + i[1]*i[1],{i[0],i[1]}});
            if(maxh.size()>k)maxh.pop();
        }
        vector<vector<int>> ans;
        while(maxh.size()>0)
        {
            vector<int> res;
            res.push_back(maxh.top().second.first);
            res.push_back(maxh.top().second.second);
            ans.push_back(res);
            maxh.pop();
        }
        return ans;
    }
};