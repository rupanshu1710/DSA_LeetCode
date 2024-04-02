class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char>mp;
        map<char,int>mp1;
        map<char,int>mp2;
        for(int i=0; i<s.size(); i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]] = t[i];
            }
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for(int i=0; i<s.size(); i++){
            s[i] = mp[s[i]];
        }
        return s==t && mp1.size()==mp2.size();
    }
};