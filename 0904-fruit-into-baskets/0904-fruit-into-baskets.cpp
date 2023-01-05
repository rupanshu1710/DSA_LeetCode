class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i=0;int j=0;
        int ans = min(n,2);
        map<int,int>mp;
        while(j<n){
            mp[fruits[j]]++;
            if(mp.size()<=2){
                ans = max(ans,j-i+1);
                j++;
            }
            else{
                while(mp.size()>2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)mp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};