class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto i:queries){
            int x = i[0];
            int y = i[1];
            int r = i[2];
            int cnt=0;
            for(auto it:points){
                int a = it[0];
                int b = it[1];
                if(abs((a-x)*(a-x)) + abs((b-y)*(b-y))<=(r*r))cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};