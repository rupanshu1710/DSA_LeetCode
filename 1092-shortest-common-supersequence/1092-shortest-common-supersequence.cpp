class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        int t[n1+1][n2+1];
        for(int i=0; i<n1+1; i++){
            for(int j=0; j<n2+1; j++){
                if(i==0 || j==0)t[i][j]=0;
            }
        }
        for(int i=1; i<n1+1; i++){
            for(int j=1; j<n2+1; j++){
                if(s1[i-1]==s2[j-1])t[i][j]=1+t[i-1][j-1];
                else{
                    t[i][j] = max(t[i][j-1],t[i-1][j]);
                }
            }
        }
        int i=n1;
        int j=n2;
        string ans;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans.push_back(s1[i-1]);
                i--;
                j--;
            }
            else{
                if(t[i][j-1]>t[i-1][j]){
                    ans.push_back(s2[j-1]);
                    j--;
                }
                else{
                    ans.push_back(s1[i-1]);
                    i--;
                }
            }
        }
        while(i>0){
            ans.push_back(s1[i-1]);
            i--;
        }
        while(j>0){
            ans.push_back(s2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};