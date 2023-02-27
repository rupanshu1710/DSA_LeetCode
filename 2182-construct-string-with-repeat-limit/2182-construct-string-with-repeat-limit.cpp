class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<int,int>>mxh;
        vector<int>mp(26,0);
        for(auto i:s){
            mp[i-'a']++;
        }
        string ans = s;
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        cout<<s<<endl;
        int i=0;
        int j = mp[s[0]-'a'];
        while(j<s.size()){
            cout<<i<<" "<<j<<endl;
            if(j-i<=repeatLimit){
                i = j;
                j += mp[s[j]-'a'];
            }
            else{
                char c = s[i+repeatLimit];
                s[i+repeatLimit] = s[j];
                mp[s[j]-'a']--;
                s[j] = c;
                i += repeatLimit+1;
                j ++;
            }
        }
        j = s.size()-1;
        char c = s[j];
        int cnt=0;
        while(j>=0 && s[j]==c){
            j--;
            cnt++;
        }
        if(cnt>repeatLimit){
            while(cnt>repeatLimit){
                cnt--;
                s.erase(s.end()-1);
            }
        }
        return s;
    }
};