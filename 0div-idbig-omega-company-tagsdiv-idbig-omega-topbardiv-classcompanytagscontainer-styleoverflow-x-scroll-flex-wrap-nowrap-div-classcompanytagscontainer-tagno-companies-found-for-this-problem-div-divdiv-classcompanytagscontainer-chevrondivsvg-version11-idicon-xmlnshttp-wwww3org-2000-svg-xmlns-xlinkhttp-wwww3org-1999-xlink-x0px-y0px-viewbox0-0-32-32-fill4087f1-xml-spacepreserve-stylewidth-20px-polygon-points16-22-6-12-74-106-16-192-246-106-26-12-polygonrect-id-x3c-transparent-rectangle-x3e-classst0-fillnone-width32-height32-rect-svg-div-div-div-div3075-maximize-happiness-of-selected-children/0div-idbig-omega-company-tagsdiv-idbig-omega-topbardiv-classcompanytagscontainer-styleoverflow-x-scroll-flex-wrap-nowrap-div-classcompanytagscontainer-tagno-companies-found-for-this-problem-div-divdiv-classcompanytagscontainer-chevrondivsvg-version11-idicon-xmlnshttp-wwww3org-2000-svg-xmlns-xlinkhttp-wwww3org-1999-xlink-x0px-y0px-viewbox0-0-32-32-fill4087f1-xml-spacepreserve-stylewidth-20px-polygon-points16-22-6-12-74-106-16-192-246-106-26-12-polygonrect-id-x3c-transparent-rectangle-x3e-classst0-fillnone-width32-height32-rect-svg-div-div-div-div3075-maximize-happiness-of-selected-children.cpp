class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(happiness.begin(),happiness.end());
        int cnt=0;
        for(int i=happiness.size()-1; i>=0 && cnt<k; i--){
            if(happiness[i]>=cnt)ans += happiness[i] - cnt;
            // else ans += happiness[i];
            cnt++;
        }
        // cout<<ans<<endl;
        return ans;
    }
};