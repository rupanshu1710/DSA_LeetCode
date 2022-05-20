class Solution {
public:
    int uniquePaths(int m, int n) {
        long long t[m][n];
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 || j==0)t[i][j]=1;
                //if(i==0 && j==0)t[i][j]=0;
            }
        }
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(i<n && j<m && i>j)t[i][j]= t[j][i];
                else t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        return  t[m-1][n-1];
        
    }
};