class Solution {
public:
    bool closeStrings(string w1, string w2) {
        map<char,int>mp1;
        map<char,int>mp2;
        map<int,vector<char>>mp3;
        map<int,vector<char>>mp4;
        for(auto i:w1){
            mp1[i]++;
        }
        for(auto i:w2){
            mp2[i]++;
        }
        for(auto i:mp1){
            mp3[i.second].push_back(i.first);
        }
        for(auto i:mp2){
            mp4[i.second].push_back(i.first);
        }
        bool flag1=1, flag2=1;
        for(auto i = mp1.cbegin(), end_mp1 = mp1.cend(),
        j = mp2.cbegin(), end_mp2 = mp2.cend();
        i != end_mp1 || j != end_mp2; i++,j++){
            if(i->first!=j->first)return 0;
        }
        // cout<<2<<endl;
        for(auto i = mp3.cbegin(), end_mp1 = mp3.cend(),
        j = mp4.cbegin(), end_mp2 = mp4.cend();
        i != end_mp1 || j != end_mp2; i++,j++){
            // cout<<i->second.size();
            if(i->first!=j->first)return 0;
            if(i->second.size()!=j->second.size())return 0;
        }
        return 1;
    }
};