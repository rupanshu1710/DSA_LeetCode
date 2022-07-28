class Solution {
public:
    bool isAnagram(string s, string t) {
        int frq1[26] = {0};
        int frq2[26]= {0};
        for(auto i:s){
            frq1[i-'a']++;
        }
        for(auto i:t){
            frq2[i-'a']++;
        }
        for(int i=0; i<26; i++){
            if(frq1[i]!=frq2[i])return 0;
        }
        return 1;
    }
};