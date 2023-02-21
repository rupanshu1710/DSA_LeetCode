class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        if(a.size()==1)return a[0];
        int low = 0;
        int high = a.size()-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid>0 && mid<a.size()-1){
                if(a[mid]!=a[mid-1] && a[mid+1]!=a[mid]){
                    return a[mid];
                }
                else if(a[mid]==a[mid-1]){
                    if((mid+1)%2==0){
                        low = mid+1;
                    }
                    else high = mid-1;
                }
                else{
                    if((mid)%2==0){
                        low = mid+1;
                    }
                    else high = mid-1;
                }
            }
            else{
                if(mid==0){
                    if(a[mid]!=a[mid+1])return a[mid];
                }
                else{
                    if(a[mid]!=a[mid-1])return a[mid];
                }
            }
        }
        return -1;
    }
};