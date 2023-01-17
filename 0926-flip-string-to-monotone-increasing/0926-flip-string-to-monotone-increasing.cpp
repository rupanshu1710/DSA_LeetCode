class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt1=0;
        int ans=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1')cnt1++;
            else{
                ans = min(ans+1,cnt1);
            }
        }
        return ans;
    }
};