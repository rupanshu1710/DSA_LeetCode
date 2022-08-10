class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)return {{1}};
        if(numRows==2)return {{1},{1,1}};
        vector<vector<int>> temp = generate(numRows-1);
        vector<int> v = temp[temp.size()-1];
        vector<int>ans(v.size()+1);
        ans[0] = 1;
        for(int i=1; i<v.size(); i++){
            ans[i] = v[i] + v[i-1];
        }
        ans[v.size()] = 1;
        temp.push_back(ans);
        return temp;
    }
};