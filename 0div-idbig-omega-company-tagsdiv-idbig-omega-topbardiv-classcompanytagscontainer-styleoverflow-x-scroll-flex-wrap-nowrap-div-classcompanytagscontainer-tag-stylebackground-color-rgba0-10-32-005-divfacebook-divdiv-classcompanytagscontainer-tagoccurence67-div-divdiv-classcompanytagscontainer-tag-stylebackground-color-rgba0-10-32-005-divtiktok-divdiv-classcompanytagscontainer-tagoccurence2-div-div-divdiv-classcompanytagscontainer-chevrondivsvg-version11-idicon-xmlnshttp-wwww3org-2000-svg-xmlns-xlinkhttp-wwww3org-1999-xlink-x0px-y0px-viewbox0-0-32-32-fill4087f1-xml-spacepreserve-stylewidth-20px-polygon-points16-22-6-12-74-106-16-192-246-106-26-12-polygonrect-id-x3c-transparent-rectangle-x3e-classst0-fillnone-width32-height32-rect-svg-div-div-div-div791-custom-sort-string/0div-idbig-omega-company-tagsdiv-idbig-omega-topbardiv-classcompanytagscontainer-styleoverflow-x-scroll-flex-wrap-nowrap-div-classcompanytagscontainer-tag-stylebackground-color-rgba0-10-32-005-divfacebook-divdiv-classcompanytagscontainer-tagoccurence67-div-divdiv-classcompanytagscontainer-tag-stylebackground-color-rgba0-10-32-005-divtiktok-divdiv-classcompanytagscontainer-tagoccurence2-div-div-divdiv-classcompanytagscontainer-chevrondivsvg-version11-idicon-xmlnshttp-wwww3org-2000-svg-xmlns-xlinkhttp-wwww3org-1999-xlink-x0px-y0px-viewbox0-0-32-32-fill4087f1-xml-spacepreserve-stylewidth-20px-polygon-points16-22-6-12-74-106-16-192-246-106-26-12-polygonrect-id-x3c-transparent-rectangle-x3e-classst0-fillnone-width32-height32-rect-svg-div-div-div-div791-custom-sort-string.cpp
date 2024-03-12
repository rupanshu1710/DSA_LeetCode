class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>mp(26,0);
        string ans = "";
        for(auto i:s){
            mp[i-'a']++;
        }
        for(auto i:order){
            if(mp[i-'a']>0){
                int k = mp[i-'a'];
                while(k--){
                    ans += i;
                }
            }
        }
        vector<int>mp1(26,0);
        for(auto i:ans){
            mp1[i-'a']++;
        }
        for(auto i:s){
            if(mp1[i-'a']==0){
                ans += i;
            }
        }
        return ans;
    }
};