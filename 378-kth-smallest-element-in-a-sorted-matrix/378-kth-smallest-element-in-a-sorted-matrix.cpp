class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),ans1,ans2;
        priority_queue<int> maxh;
        for(auto i:matrix){
            for(auto j:i){
                maxh.push(j);
                if(maxh.size()>k)maxh.pop();
            }
        }
        return maxh.top();
    }
};