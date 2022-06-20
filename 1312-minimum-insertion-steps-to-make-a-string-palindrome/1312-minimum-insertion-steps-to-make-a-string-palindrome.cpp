class Solution {
public:
    int minInsertions(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        int n1 = s.size();
        int n2 = r.size();
        int t[n1+1][n2+1];
        for(int i=0; i<n1+1; i++){
            for(int j=0; j<n2+1; j++){
                if(i==0 || j==0)t[i][j]=0;
            }
        }
        for(int i=1; i<n1+1; i++){
            for(int j=1; j<n2+1; j++){
                if(r[j-1]==s[i-1])t[i][j]=1+t[i-1][j-1];
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return n1 - t[n1][n2];
        
    }
};