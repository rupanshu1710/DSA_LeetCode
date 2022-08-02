class Solution {
public:
    int count(int k, vector<vector<int>>& matrix){
        int ans=0;
        for(int i=0; i<matrix.size(); i++){
            ans += upper_bound(matrix[i].begin(),matrix[i].end(),k) - matrix[i].begin();
        }
        return ans;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),ans1,ans2;
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low<high){
            int mid = low +(high-low)/2;
            if(count(mid,matrix)<k)low = mid+1;
            else high = mid;
        }
        return low;
    }
};