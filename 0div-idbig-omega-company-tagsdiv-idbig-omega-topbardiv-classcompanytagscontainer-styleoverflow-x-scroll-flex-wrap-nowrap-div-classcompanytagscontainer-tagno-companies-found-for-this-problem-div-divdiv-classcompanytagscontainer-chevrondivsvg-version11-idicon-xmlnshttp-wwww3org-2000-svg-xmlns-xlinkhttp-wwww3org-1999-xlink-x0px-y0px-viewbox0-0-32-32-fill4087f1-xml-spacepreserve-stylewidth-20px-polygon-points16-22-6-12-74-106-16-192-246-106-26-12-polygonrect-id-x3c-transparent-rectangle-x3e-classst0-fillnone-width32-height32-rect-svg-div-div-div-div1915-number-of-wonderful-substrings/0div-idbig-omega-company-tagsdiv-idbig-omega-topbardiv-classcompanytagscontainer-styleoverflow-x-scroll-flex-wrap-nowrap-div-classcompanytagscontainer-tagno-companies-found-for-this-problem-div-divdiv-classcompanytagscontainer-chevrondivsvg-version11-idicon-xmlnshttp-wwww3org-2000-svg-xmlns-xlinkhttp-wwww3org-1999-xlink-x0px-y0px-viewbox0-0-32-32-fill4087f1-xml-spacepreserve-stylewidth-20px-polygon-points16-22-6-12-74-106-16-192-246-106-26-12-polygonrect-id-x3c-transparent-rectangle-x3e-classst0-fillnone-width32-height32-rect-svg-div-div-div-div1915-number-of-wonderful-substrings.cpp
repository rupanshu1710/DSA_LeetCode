class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        ll ans=0;
        unordered_map<ll,ll>mp;
        vector<ll>temp(10,0);
        ll x = 0,n=word.size();
        mp[x]++;
        for(int i=0; i<n; i++){
            // cout<<x<<endl;
            x ^= 1<<(int)(word[i]-'a');
            ans += mp[x];
            // cout<<ans<<endl;
            for(int i=0; i<10; i++){
                ll y = x^(1<<i);
                // if(x==2)cout<<y<<endl;
                ans += mp[y];
            }
            // cout<<ans<<endl;
            mp[x]++;
        }
        return ans;
    }
};