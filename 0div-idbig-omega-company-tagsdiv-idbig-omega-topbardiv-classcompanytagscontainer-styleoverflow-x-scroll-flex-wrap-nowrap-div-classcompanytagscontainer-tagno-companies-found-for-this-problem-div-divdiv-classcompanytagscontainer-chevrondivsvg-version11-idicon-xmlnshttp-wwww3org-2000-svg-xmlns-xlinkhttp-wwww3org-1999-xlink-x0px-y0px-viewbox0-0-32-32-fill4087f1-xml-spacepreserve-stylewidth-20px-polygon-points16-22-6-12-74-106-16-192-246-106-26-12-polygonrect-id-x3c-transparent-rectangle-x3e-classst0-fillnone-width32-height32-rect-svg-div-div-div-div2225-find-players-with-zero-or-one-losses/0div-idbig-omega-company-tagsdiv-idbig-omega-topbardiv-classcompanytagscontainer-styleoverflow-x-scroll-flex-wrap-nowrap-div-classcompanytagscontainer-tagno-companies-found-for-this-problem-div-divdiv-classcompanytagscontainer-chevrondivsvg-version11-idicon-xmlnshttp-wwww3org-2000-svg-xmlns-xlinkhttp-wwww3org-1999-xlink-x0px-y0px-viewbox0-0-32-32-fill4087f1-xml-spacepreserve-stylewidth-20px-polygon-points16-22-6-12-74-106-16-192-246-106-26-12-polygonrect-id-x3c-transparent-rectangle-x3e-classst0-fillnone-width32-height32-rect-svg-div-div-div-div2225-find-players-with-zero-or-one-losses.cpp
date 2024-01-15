class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        map<int,int>win;
        map<int,int>loose;
        for(auto i:matches){
            win[i[0]]++;
            loose[i[1]]++;
        }
        vector<int>temp;
        for(auto i:win){
            if(loose.find(i.first)==loose.end()){
                temp.push_back(i.first);
            }
        }
        ans.push_back(temp);
        vector<int>temp1;
        for(auto i:loose){
            if(i.second==1){
                temp1.push_back(i.first);
            }
        }
        ans.push_back(temp1);
        return ans;
    }
};