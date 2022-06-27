class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>frq;
        for(int i=0; i<nums.size(); i++){
            frq[nums[i]]++;
        }
        priority_queue<pair<int,int>> maxh;
        for(auto i=frq.begin(); i!=frq.end(); i++){
            maxh.push({-i->second,i->first});
        }
        vector<int> ans;
        while(!maxh.empty()){
            int a = abs(maxh.top().first);
            while(a){
                ans.push_back(maxh.top().second);
                a--;
            }
            maxh.pop(); 
        }
        return ans;
    }
};