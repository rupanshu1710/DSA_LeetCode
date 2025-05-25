class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        int ans = 0;
        unordered_map<string,int>mp;

        for(int i=0; i<n; i++){
            string s = words[i];
            reverse(s.begin(),s.end());

            if(mp.find(s)!=mp.end() && mp[s]>0){
                ans += 4;
                mp[s]--;
            }
            else{
                mp[words[i]]++;
            }
        }
        for(auto& i:mp){
            string s = i.first;
            reverse(s.begin(),s.end());
            if(i.first==s && mp[s]>0 && i.second>0){
                ans+=2;
                return ans;
            }
        }
        return ans;
    }
};