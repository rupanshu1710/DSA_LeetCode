class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int>mp(26,0);
        vector<int>mp1(26,0);
        string ans = "";
        for(int i=0; i<26; i++){
            mp[i] = i;
        }
        for(int i=0; i<s1.size(); i++){
            mp[s1[i]-'a'] =min(mp[s1[i]-'a'],mp[s2[i]-'a']);
            mp[s2[i]-'a'] = mp[s1[i]-'a'];
            cout<<s1[i]<<" "<<s2[i]<<" "<<mp[s2[i]-'a']<<" "<<mp[s1[i]-'a']<<endl;
        }
        while(mp1!=mp){
            mp1 = mp;
            for(int i=0; i<s1.size(); i++){
                mp[s1[i]-'a'] =min(mp[s1[i]-'a'],mp[s2[i]-'a']);
                mp[s2[i]-'a'] = mp[s1[i]-'a'];
                // cout<<s1[i]<<" "<<s2[i]<<" "<<mp[s2[i]-'a']<<" "<<mp[s1[i]-'a']<<endl;
            }
        }
        for(int i=0; i<baseStr.size(); i++){
            ans += mp[baseStr[i]-'a'] + 'a';
        }
        return ans;
    }
};