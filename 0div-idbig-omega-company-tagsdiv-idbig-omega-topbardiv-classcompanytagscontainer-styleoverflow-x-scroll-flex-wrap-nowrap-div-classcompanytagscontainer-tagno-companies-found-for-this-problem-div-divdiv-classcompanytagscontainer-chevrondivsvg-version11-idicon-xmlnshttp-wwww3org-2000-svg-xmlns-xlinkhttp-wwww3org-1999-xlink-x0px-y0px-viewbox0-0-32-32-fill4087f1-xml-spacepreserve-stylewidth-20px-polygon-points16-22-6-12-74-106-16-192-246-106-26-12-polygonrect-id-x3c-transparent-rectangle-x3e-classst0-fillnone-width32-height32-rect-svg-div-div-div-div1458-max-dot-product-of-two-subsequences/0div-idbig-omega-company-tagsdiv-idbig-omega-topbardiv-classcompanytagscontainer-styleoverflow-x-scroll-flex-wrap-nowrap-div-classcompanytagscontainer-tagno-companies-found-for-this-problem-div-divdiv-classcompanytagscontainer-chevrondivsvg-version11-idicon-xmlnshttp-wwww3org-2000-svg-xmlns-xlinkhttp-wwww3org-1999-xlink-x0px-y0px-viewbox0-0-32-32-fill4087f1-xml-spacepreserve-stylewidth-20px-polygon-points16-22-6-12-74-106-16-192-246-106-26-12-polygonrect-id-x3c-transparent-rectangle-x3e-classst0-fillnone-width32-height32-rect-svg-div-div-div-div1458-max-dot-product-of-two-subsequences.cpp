class Solution {
public:
    int dp[501][501];
    int getAns(vector<int>& nums1, vector<int>& nums2,int i,int j){
        if(i==nums1.size()|| j==nums2.size())return 0;
        if(dp[i][j] !=INT_MIN)return dp[i][j];
        if(nums1[i]*nums2[j]>=0){
            return dp[i][j] = max({nums1[i]*nums2[j] + getAns(nums1,nums2,i+1,j+1),getAns(nums1,nums2,i,j+1),getAns(nums1,nums2,i+1,j)});
        }
        else return dp[i][j] = max({getAns(nums1,nums2,i,j+1),getAns(nums1,nums2,i+1,j)});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0; i<501; i++){
            for(int j=0; j<501; j++){
                dp[i][j] = INT_MIN;
            }
        }
        ans =  getAns(nums1,nums2,0,0);
        if(ans==0){
            int a = *max_element(nums1.begin(),nums1.end());
            int b = *max_element(nums2.begin(),nums2.end());
            if(a==0 || b==0)return ans;
            else if(a<0 && b<0){
                return a*b;
            }
            else if(a<0){
                b = *min_element(nums2.begin(),nums2.end());
                return a*b;
            }
            else{
                a = *min_element(nums1.begin(),nums1.end());
                return a*b;
            }
        }
        return ans;
    }
};