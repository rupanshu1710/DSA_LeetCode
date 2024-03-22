class Solution {
public:
    long long countSubstrings(string s, char c) {
        int n = 0;
        long long ans = 0;
        for(auto i:s){
            if(i==c)n++;
        }
        ans = (long long)n*(n+1)/2;
        return ans;
    }
};