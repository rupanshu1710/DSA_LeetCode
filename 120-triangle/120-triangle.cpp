class Solution {
public:
    int t[201][201];
    int getAns(vector<vector<int>>& triangle, int i, int j){
        if(i>triangle.size()-1)return 0;
        if(t[i][j]!=-1)return t[i][j];
        return t[i][j] = triangle[i][j] + min(getAns(triangle,i+1,j+1),getAns(triangle,i+1,j));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(t,-1,sizeof(t));
        return getAns(triangle,0,0);
    }
};