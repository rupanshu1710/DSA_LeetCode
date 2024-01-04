class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
        }
        int ans=0;
        for(auto i:mp){
            int x = i.second;
            if(x==1)return -1;
            else{
                if(x%3==0){
                    ans += x/3;
                }
                else if(x%3==1){
                    ans += (x-4)/3 + 2; 
                }
                else{
                    ans += (x-2)/3 + 1;
                }
            }
        }
        return ans;
    }
};