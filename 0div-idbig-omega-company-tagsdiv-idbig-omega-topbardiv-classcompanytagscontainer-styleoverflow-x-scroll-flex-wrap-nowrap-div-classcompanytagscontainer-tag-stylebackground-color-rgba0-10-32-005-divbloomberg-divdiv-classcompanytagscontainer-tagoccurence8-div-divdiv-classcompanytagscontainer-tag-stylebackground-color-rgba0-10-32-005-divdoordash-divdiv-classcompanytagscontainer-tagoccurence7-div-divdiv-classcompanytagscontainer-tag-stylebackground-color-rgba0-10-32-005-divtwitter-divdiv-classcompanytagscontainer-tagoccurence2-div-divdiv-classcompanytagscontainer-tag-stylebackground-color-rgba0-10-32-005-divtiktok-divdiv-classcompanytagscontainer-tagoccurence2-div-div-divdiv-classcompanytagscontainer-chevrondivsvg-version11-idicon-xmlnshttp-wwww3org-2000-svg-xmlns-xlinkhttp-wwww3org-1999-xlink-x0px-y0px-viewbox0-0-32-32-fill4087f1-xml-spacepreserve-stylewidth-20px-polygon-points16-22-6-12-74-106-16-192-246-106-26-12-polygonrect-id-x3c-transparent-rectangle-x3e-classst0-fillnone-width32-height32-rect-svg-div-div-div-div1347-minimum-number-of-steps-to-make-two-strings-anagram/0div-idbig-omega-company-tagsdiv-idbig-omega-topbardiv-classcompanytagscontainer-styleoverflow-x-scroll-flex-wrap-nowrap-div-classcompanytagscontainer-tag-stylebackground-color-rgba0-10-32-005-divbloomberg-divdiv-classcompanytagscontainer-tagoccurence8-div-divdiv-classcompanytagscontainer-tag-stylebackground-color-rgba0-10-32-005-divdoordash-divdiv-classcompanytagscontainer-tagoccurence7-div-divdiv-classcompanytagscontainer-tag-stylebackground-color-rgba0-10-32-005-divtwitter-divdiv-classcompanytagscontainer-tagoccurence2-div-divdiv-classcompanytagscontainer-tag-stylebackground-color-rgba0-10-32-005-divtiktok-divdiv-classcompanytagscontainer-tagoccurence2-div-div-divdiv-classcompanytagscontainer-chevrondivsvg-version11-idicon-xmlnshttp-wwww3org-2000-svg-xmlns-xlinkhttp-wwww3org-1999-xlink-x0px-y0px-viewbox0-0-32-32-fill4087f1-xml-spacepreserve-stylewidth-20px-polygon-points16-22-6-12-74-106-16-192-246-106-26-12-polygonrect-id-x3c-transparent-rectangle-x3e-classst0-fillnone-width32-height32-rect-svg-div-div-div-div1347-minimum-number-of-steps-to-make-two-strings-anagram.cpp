class Solution {
public:
    int minSteps(string s, string t) {
        int ans=0;
        map<char,int>mp1;
        map<char,int>mp2;
        for(auto i:s){
            mp1[i]++;
        }
        for(auto i:t){
            mp1[i]--;
        }
        for(auto i:mp1){
            if(i.second>0){
                ans += i.second;
                // cout<<ans<<endl;
            }
        }
        // cout<<ans<<endl;
        return ans;
    }
};