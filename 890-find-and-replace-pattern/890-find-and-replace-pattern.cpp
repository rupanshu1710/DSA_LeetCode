class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto i:words){
            unordered_map<char,char>mp1;
            unordered_map<char,char>mp2;
            for(auto j=0; j<pattern.size(); j++){
                if(mp1.find(pattern[j])!=mp1.end()){
                    if(mp1[pattern[j]]!=i[j])break;
                }
                if(mp2.find(i[j])!=mp2.end()){
                    if(mp2[i[j]]!=pattern[j])break;
                }
                mp1[pattern[j]]=i[j];
                mp2[i[j]]=pattern[j];
                if(j==pattern.size()-1)ans.push_back(i);
            }
        }
        return ans;
    }
};