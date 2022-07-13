class Solution {
public:
    unordered_map<string,bool>mp;
    bool solve(string s1, string s2){
        string s = s1 + " " + s2;
        if(mp.find(s)!=mp.end())return mp[s];
        if(s1==s2)return mp[s]=1;
        int n = s1.size();
        if(n<=1)return 0;
        bool ans = 0;
        for(int i=1; i<n; i++){
            bool contd1= solve(s1.substr(0, i), s2.substr(n-i)) && solve(s1.substr(i), s2.substr(0, n-i));
            bool contd2= solve(s1.substr(0, i), s2.substr(0, i)) && solve(s1.substr(i), s2.substr(i));;
            if(contd1 || contd2){
                ans = 1;
                break;
            }
        }
        return mp[s] = ans;
    }
    bool isScramble(string s1, string s2) {
        vector<int> cnt(26, 0);
        mp=unordered_map<string, bool>(false);
        /*for(int i=0; i<s1.size(); i++){
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(cnt[i]!=0) return false;
        }*/
        return solve(s1, s2);
    }
};