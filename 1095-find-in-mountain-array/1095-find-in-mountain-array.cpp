/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int b, MountainArray &mountainArray) {
        int n = mountainArray.length();
        int low=0;
        int high = n-1;
        int peakIdx=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(mid!=0 && mid!=n-1){
                int x = mountainArray.get(mid);
                int y = mountainArray.get(mid+1);
                int z = mountainArray.get(mid-1);
                if(x>y && x>z){
                    peakIdx = mid;
                    break;
                }
                else if(x>y){
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }
            else{
                if(mid==0){
                    if(mountainArray.get(mid)>mountainArray.get(mid+1))peakIdx = 0;
                    else peakIdx = 1;
                    break;
                }
                else{
                    if(mountainArray.get(mid)>mountainArray.get(mid-1))peakIdx = n-1;
                    else peakIdx = n-2;
                    break;
                }
            }
        }
        low = 0;
        high = peakIdx-1;
        int ans=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int x = mountainArray.get(mid);
            if(x==b){
                ans = mid;
                break;
            }
            else if(x>b){
                high = mid-1;
            }
            else low = mid+1;
        }
        if(ans!=-1)return ans;
        low = peakIdx;
        high = n-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            int x = mountainArray.get(mid);
            if(x==b){
                ans = mid;
                break;
            }
            else if(x<b){
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */
// int solve(int* a, int n, int b) {
    
// }
