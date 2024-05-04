class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans=0,sum=0;
        int n = reward1.size();
        int x = n-k;
        for(int i=0; i<n; i++){
            sum += reward2[i];
            reward1[i] -= reward2[i];
        }
        sort(reward1.begin(),reward1.end());
        int i=n-1;
        ans += sum;
        while(k--){
            ans += reward1[i];
            i--;
        }
        return ans;
    }
};