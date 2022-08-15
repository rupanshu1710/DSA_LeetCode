class Solution {
public:
    int maximalSquare(vector<vector<char>>matrix) {
        int mx=0;
        int n = matrix.size();
        int m = matrix[0].size();
        int t[n+1][m+1];
        memset(t,0,sizeof(t));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int right = t[i][j+1];
                int diag = t[i+1][j+1];
                int down = t[i+1][j];
                if(matrix[i][j]=='1'){
                    t[i][j] = 1 + min(right,min(diag,down));
                    mx = max(mx,t[i][j]);
                }
                else t[i][j] = 0;
            }
        }
        return mx*mx;
    }
};