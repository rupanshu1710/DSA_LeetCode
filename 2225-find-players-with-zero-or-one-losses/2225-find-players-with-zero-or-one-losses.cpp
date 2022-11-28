class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>winner;
        map<int,int>losser;
        int n = matches.size();
        for(int i=0; i<n; i++){
            if(losser.find(matches[i][0])==losser.end()){
                winner[matches[i][0]]++;
            }
            losser[matches[i][1]]++;
        }
        vector<int>temp2;
        for(auto i:losser){
            if(i.second==1)temp2.push_back(i.first);
        }
        vector<int>temp;
        vector<vector<int>>ans;
        for(auto i:winner){
            if(losser.find(i.first)==losser.end()){
                temp.push_back(i.first);
            }
        }
        ans.push_back(temp);
        ans.push_back(temp2);
        return ans;
    }
};