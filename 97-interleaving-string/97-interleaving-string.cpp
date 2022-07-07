class Solution {
public:
    unordered_map<string,bool> mp;
    bool getAns(string s1, string s2, string s3, int i, int j, int k){
        if(k==s3.size()) return (i==s1.size() and j==s2.size())?1:0;
        string temp = to_string(i) + "*" + to_string(j);
        if(mp.find(temp)!=mp.end())return mp[temp];
        if(i==s1.size()) return s2[j]==s3[k]?getAns(s1,s2,s3,i,j+1,k+1):0;
        if(j==s2.size()) return s1[i]==s3[k]?getAns(s1,s2,s3,i+1,j,k+1):0;
        bool c1 = 0,c2=0;
        if(s1[i]==s3[k]) c1 =  getAns(s1,s2,s3,i+1,j,k+1);
        if(s2[j]==s3[k]) c2 =  getAns(s1,s2,s3,i,j+1,k+1);
        return mp[temp] = c1 or c2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        return getAns(s1,s2,s3,0,0,0);
    }
};