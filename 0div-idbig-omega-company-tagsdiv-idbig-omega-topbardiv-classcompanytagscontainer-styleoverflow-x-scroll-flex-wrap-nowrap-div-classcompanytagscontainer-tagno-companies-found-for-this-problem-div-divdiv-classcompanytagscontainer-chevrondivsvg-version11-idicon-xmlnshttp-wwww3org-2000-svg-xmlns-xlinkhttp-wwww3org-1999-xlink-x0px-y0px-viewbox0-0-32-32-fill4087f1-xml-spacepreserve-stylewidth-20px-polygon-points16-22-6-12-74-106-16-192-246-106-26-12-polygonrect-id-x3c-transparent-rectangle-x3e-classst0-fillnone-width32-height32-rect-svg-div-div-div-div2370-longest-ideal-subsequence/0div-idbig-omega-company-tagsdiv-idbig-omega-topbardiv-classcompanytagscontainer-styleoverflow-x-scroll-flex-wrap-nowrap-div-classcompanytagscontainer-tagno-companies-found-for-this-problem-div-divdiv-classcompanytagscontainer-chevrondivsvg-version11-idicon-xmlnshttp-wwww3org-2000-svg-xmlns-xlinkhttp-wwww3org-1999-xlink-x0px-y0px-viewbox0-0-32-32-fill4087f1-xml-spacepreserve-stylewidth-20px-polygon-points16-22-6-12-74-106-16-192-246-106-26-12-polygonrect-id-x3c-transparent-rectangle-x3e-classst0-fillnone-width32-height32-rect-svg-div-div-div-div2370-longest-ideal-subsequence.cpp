class Solution {
public:
    int longestIdealString(string s, int k) {
        int n= s.size();
        vector<int>dp(n,1);
        vector<int>temp(26,0);
        for(int i=0; i<n; i++){
            int idx = s[i]-'a';
            int start = max(0,idx-k);
            int end = min(25,idx+k);
            int mx = 0;
            for(int j=start; j<=end; j++){
                mx = max(mx,temp[j]);
            }
            dp[i] = max(dp[i],mx+1);
            temp[idx] = dp[i];
        }
        return *max_element(dp.begin(),dp.end());
    }
};