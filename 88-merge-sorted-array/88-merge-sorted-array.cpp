class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int k = m+n-1;
        while(j>=0 && i>=0){
            if(nums1[i]<=nums2[j]){
                long long temp = nums2[j];
                nums2[j] = nums1[k];
                nums1[k] = temp;
                j--;
                k--;
            }
            else{
                long long temp = nums1[i];
                nums1[i] = nums1[k];
                nums1[k] = temp;
                i--;
                k--;
            }
        }
        if(j!=-1){
            k=j;
            while(j!=-1){
                long long temp = nums2[j];
                nums2[j] = nums1[j];
                nums1[k] = temp;
                k--;
                j--;
            }
        }
    }
};