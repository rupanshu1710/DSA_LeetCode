class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        while(mp.size()!=0){
            vector<int>temp;
            for(auto i:mp){
               cout<<i.first<<" "<<i.second<<" ";
                if(i.second!=0)temp.push_back(i.first);
                mp[i.first]--;
                
            }
        // cout<<mp.size()<<endl;
            for(auto i:mp){
                if(i.second<=0){
                        mp.erase(i.first);
                    }
               // cout<<i.first<<" "<<i.second;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};