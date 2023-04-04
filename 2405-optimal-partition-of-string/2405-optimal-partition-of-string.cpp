class Solution {
public:
    int partitionString(string s) {
        int ans=1;
        int n = s.size();
        map<char,int>mp;
        for(int i=0; i<n; i++){
            if(mp.find(s[i])!=mp.end()){
                ans++;
                mp.clear();
            }
            mp[s[i]]++;
        }
        return ans;
    }
};