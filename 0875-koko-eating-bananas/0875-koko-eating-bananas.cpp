class Solution {
public:
    bool isans(vector<int>& piles, int h, int temp)
    {
        int n = piles.size();
        for(int i=0; i<n; i++)
        {
            int x = (piles[i]+temp-1)/temp ;
            h = h-x;
            if(h<0)return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long sum = 0;
        int mx = INT_MIN;
        for(int i=0; i<n; i++)
        {
            sum += piles[i];
            mx = max(mx,piles[i]);
        }
        int low  = (sum+h-1)/h;
        int high = mx;
        int ans;
        while(low<=high)
        {
            int mid = (low - high)/2 + high;
            if(isans(piles,h,mid))
            {
                high = mid-1;
                ans = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        return ans;
        
    }
};