class Solution {
public:
    int getAns(string& s,unordered_set<string>& st, int i, int& n,unordered_map<int,int>& mp){
        if(i>=n){
            return 0;
        }
        
        if(mp.count(i)){
            return mp[i];
        }
        
        int result = 1 + getAns(s,st,i+1,n,mp);
        
        for(int j=i; j<n; j++){
            string curr = s.substr(i,j-i+1);
            if(st.count(curr)){
                result = min(result, getAns(s,st,j+1,n,mp));
            }
        }
        
        return mp[i] = result;
    }
    int minExtraChar(string s, vector<string>& dic) {
        int n = s.size();
        unordered_map<int,int>mp;
        unordered_set<string> st(begin(dic),end(dic)); 
        
        return getAns(s,st,0,n,mp);
    }
};




