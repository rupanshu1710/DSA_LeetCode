class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>>mp;
        for(auto i:adjacentPairs){
            mp[i[0]].push_back(i[1]);
            mp[i[1]].push_back(i[0]);
        }
        int n = mp.size();
        int temp=-1;
        vector<int>ans;
        for(auto i:mp){
            if(i.second.size()==1){
                temp = i.first;
            }
        }
        map<int,int>mp1;
        // cout<<temp<<endl;
        while(mp1.find(temp)==mp1.end()){
            // cout<<temp<<endl;
            ans.push_back(temp);
            mp1[temp]++;
            if(mp[temp].size()==1){
                temp = mp[temp][0];
            }
            else{
                int a = mp[temp][0];
                int b = mp[temp][1];
                if(mp1.find(a)==mp1.end()){
                    temp=a;
                }
                else temp=b;
            }
        }
        return ans;
    }
};