class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>mp;
        int x=0;
        for(auto i:order){
            mp[i] = x;
            x++;
        }
        for(int i=1; i<words.size(); i++){
            string s1 = words[i-1];
            string s2 = words[i];
            int n = min(s1.size(),s2.size());
            int j=0;
            for(j=0; j<n; j++){
                if(mp[s1[j]]<mp[s2[j]])break;
                else if(mp[s1[j]]==mp[s2[j]])continue;
                else return 0;
            }
            if(j==n && s2.size()<s1.size())return 0;
        }
        return 1;
    }
};