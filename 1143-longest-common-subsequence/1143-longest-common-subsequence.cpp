class Solution {
public:
    int t[1001][1001];
    int getAns(string &text1, string &text2, int n1, int n2){
        if(n1==0 || n2==0)return 0;
        if(t[n1][n2]!=-1)return t[n1][n2];
        if(text1[n1-1]==text2[n2-1])return t[n1][n2] = 1 + getAns(text1,text2,n1-1,n2-1);
        else{
            return t[n1][n2] = max(getAns(text1,text2,n1-1,n2),getAns(text1,text2,n1,n2-1));
        }
        return t[n1][n2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        return getAns(text1,text2,text1.size(),text2.size());
    }
};