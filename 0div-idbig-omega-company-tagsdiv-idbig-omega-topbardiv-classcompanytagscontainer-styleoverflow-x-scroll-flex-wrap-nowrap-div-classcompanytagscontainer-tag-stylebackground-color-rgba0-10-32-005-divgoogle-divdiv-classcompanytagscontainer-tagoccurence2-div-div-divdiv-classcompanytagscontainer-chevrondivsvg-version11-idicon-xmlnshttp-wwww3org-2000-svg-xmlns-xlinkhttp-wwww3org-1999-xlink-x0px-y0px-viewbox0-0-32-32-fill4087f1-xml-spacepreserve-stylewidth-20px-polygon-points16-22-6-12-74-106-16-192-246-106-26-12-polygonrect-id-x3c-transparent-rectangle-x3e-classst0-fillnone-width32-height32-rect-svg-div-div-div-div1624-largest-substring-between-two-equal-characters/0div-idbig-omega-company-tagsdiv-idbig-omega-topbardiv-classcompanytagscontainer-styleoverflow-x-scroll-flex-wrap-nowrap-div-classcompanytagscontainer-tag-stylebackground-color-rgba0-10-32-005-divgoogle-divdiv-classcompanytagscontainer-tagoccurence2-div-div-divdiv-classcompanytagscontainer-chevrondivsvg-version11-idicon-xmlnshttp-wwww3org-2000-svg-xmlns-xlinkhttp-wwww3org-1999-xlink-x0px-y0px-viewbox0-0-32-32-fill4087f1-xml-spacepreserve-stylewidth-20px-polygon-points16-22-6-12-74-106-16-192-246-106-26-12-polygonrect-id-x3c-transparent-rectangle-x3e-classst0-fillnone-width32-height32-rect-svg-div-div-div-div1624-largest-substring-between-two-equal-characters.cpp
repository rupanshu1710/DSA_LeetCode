class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map<char,vector<int>>mp;
        int n = s.size();
        for(int i=0; i<n; i++){
            mp[s[i]].push_back(i);
        }
        int ans = INT_MIN;
        for(auto i:mp){
            ans = max(ans,i.second[i.second.size()-1] - i.second[0] - 1);
        }
        return ans;
    }
};