class Solution {
public:
    bool check(int temp, vector<int>& weights, int days){
        int ans=0;
        int sum=0;
        for(int i=0; i<weights.size(); i++){
             
            sum += weights[i];
            if(sum>temp){
                ans++;
                sum = weights[i];
            }
            // cout<<sum<<" ";
            
        }
        ans++;
        if(sum>temp)ans++;
        return ans<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        for(auto i:weights){
            low = max(low,i);
            high += i;
        }
        int ans=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(check(mid,weights,days)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        // cout<<check(10,weights,days)<<endl;
        return ans;
    }
};