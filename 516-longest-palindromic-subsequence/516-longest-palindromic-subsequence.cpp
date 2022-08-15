class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        string s2 = s1;
        reverse(s1.begin(),s1.end());
        int n = s1.size();
        int t[n+1][n+1];
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                if(i==0||j==0)t[i][j]=0;
                else t[i][j]=-1;
            }
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(t[i][j]==-1){
                    if(s1[i-1]==s2[j-1])t[i][j] = 1 + t[i-1][j-1];
                    else t[i][j] = max(t[i][j-1], t[i-1][j]);
                }
            }
        }
        return t[n][n];
    }
};