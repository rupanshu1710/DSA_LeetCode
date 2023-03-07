class Solution {
public:
    bool check(long long mid, vector<int>& time, int totalTrips){
        long long ans = 0;
        for(int i=0; i<time.size(); i++){
            ans += mid/(long long)time[i];
            if(ans>=totalTrips)return 1;
        }
        if(ans<totalTrips)return 0;
        return 1;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans=-1;
        long long low = 0;
        long long high = LLONG_MAX;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(check(mid,time,totalTrips)){
                high = mid-1;
                ans = mid;
            }
            else low = mid+1;
        }
        return ans;
    }
};