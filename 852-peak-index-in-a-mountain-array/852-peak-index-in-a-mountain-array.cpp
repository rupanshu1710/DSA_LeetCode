class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int low=0;
        int high = n-1;
        int mid;
        while(low<=high)
        {
            mid = low + (high-low)/2;
            if( mid<n-1 && arr[mid]<arr[mid+1])
            {
                low=mid+1;
            }
            else if(mid>0 &&  arr[mid]<arr[mid-1])
            {
                high = mid-1;
            }
            else
            {
                break;
            }
        }
        return mid;
        
        
    }
};