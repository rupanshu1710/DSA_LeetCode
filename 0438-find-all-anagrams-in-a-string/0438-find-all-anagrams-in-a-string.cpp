class Solution {
public:
    bool isAnagram(string t, string p, map<char,int>mp){
        map<char,int>mp2;
        for(auto i:t){
            mp2[i]++;
        }
        return mp==mp2;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        if(n>s.size())return {};
        vector<int>ans;
        vector<int>mp(26,0);
         vector<int>mp2(26,0);
        for(auto i:p){
            mp[i-'a']++;
        }
        for(int i=0; i<n; i++){
            mp2[s[i]-'a']++;
        }
        if(mp==mp2){
            ans.push_back(0);
        }
        for(int i=n; i<s.size(); i++){
            mp2[s[i-n]-'a']--;
            mp2[s[i]-'a']++;
            if(mp==mp2){
                ans.push_back(i-n+1);
            }
        }
        return ans;
    }
};