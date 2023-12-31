class Solution {
public:
    bool makeEqual(vector<string>& words) {
        map<char,int>mp;
        for(auto i:words){
            for(auto it:i){
                mp[it]++;
            }
        }
        for(auto i:mp){
            if(i.second%(words.size())!=0)return 0;
        }
        return 1;
    }
};