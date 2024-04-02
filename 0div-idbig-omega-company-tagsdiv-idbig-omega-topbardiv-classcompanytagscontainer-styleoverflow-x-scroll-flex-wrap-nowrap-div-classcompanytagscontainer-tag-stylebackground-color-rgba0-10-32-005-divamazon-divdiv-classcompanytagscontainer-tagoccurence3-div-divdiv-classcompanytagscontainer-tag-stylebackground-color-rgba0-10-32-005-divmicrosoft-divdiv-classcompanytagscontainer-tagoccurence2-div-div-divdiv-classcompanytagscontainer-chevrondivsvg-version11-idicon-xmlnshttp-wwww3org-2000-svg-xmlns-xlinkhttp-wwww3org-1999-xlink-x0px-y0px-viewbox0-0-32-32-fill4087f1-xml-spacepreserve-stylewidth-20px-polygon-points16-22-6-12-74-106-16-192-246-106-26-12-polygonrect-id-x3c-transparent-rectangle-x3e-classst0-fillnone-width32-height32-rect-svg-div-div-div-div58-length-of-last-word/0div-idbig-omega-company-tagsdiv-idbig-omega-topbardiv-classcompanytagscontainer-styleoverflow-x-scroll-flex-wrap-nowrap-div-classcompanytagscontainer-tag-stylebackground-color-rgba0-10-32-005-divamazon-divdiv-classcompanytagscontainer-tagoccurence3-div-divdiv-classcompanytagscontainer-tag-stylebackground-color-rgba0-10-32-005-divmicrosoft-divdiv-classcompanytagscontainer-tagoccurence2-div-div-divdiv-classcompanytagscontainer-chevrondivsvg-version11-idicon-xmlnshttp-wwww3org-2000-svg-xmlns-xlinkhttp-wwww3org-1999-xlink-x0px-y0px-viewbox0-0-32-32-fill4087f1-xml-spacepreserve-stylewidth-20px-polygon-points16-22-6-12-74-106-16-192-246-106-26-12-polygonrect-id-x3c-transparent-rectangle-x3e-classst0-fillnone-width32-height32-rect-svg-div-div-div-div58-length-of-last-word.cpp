class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int ans=0;
        int i=0;
        while(s[i]==' ')i++;
        while(ans + i<s.size() && s[ans+i]!=' ')ans++;
        return ans;
    }
};