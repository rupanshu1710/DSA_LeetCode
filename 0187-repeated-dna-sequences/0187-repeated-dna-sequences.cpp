class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string,int>mp;
        if(s.size()<10)return ans;
        string temp = s.substr(0,10);
        mp[temp]++;
        for(int i=10; i<s.size(); i++){
            temp.erase(temp.begin());
            temp.push_back(s[i]);
            mp[temp]++;
            // cout<<temp<<endl;
        }
        for(auto i:mp){
            if(i.second>1)ans.push_back(i.first);
        }
        return ans;
    }
};