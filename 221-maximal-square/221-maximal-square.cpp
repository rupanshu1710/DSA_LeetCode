class Solution {
public:
    int t[301][301]; 
    int getAns(vector<vector<char>>& matrix,int i, int j,int& mx){
        if(i>=matrix.size() || j>=matrix[0].size())return 0;
        if(t[i][j]!=-1)return t[i][j];
        int right = getAns(matrix,i,j+1,mx);
        int diag = getAns(matrix,i+1,j+1,mx);
        int down = getAns(matrix,i+1, j,mx);
        if(matrix[i][j]=='1'){
            int ans = 1 + min(right,min(diag,down));
            mx = max(mx,ans);
            return t[i][j] = ans;
        }
        else return t[i][j] = 0;
    }
    int maximalSquare(vector<vector<char>>matrix) {
        int mx=0;
        memset(t,-1,sizeof(t));
        getAns(matrix,0,0,mx);
        return mx*mx;
    }
};