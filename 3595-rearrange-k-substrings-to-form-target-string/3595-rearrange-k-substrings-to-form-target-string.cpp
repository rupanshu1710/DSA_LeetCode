class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int n = s.size();
        k = n/k;
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;
        for(int i=0; i<n; i+=k){
            string str = t.substr(i,k);
            string str1 = s.substr(i,k);
            mp1[str]++;
            mp2[str1]++;
        }
        return mp2==mp1;
    }
};