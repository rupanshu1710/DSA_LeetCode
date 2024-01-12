class Solution {
public:
    bool halvesAreAlike(string s) {
        // string s1 = s.substr(0,s.size()/2);
        // string s2 = s.substr(s.size()/2,s.size()/2);
        int cnt1=0,cnt2=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                if(i<s.size()/2)cnt1++;
                else cnt2++;
            }
        }
        return cnt1==cnt2;
    }
};