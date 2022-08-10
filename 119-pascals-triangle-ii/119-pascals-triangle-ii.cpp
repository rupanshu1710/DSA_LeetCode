class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0)return {1};
        if(rowIndex==1)return {1,1};
        vector<int> v = getRow(rowIndex-1);
        vector<int>ans(v.size()+1);
        ans[0] = 1;
        for(int i=1; i<v.size(); i++){
            ans[i] = v[i] + v[i-1];
        }
        ans[v.size()] = 1;
        return ans;
    }
};