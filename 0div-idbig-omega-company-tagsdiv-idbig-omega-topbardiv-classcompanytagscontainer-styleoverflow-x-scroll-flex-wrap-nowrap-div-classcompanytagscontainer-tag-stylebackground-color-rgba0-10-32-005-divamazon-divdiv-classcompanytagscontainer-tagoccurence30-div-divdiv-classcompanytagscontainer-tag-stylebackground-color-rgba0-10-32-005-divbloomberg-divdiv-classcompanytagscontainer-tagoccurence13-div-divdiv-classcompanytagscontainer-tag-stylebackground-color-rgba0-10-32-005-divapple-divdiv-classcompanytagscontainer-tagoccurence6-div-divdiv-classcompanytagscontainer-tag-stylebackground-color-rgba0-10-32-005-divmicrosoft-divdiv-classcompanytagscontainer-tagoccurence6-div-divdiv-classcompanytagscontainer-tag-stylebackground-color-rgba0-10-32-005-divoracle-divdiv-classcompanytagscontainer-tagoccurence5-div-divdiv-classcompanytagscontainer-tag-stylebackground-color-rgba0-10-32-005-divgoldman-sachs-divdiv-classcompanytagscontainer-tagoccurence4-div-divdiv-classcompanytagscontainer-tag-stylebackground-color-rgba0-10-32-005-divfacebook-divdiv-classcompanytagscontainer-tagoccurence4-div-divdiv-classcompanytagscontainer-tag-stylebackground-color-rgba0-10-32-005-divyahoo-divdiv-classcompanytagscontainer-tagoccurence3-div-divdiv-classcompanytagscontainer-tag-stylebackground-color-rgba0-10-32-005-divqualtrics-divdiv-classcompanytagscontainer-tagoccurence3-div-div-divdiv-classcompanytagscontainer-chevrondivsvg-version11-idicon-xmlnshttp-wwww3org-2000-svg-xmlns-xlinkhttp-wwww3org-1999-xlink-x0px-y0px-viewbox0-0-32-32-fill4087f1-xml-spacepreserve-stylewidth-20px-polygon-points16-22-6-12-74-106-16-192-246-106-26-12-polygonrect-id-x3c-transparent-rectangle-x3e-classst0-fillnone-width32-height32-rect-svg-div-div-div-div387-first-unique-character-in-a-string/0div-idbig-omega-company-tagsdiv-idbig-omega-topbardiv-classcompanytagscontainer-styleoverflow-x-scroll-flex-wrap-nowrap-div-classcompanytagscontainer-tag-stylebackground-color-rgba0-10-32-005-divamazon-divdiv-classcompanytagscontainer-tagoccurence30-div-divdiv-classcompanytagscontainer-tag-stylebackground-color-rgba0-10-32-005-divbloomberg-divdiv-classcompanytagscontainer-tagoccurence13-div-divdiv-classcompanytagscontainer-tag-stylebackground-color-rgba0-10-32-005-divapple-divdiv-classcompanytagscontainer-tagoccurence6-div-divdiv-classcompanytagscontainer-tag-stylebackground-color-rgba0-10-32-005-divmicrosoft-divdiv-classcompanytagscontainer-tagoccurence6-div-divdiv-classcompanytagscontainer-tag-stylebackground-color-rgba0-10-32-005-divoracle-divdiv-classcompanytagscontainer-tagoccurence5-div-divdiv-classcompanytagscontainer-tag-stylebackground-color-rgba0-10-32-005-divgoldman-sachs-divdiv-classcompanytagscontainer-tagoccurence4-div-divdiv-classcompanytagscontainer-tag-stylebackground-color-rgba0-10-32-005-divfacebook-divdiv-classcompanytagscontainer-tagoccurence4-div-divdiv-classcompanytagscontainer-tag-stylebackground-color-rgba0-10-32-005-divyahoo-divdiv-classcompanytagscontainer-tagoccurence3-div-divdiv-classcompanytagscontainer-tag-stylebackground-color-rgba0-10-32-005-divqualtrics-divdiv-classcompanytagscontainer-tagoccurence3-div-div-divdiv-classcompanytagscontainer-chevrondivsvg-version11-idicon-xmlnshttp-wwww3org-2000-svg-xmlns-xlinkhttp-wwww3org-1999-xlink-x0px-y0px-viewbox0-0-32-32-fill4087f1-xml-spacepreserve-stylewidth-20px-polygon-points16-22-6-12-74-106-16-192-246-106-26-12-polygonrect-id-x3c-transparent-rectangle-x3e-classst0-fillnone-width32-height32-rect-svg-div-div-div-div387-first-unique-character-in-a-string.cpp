class Solution {
public:
    int firstUniqChar(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int ans=0;
        for(auto i:s){
            if(mp[i]==1){
                return ans;
            }
            ans++;
        }
        return -1;
        
    }
};