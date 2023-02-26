class Solution {
public:
    int t[501][501];
    int getAns(string s1, string s2,int i,int j){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(t[i][j]!=-1)return t[i][j];
        if(s1[i]==s2[j])return t[i][j] =  getAns(s1,s2,i-1,j-1);
        return t[i][j] =  1 + min(getAns(s1,s2,i,j-1),min(getAns(s1,s2,i-1,j-1),getAns(s1,s2,i-1,j)));
    }
    int minDistance(string s1, string s2){
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1==0)return n2;
        if(n2==0)return n1;
        memset(t,-1,sizeof(t));
        return getAns(s1,s2,n1-1,n2-1);
    }
};