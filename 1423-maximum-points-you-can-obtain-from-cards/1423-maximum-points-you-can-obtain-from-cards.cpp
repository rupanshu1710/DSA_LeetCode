class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum=0;
        int n = cardPoints.size();
        for(int i=0; i<n; i++){
            totalSum+=cardPoints[i];
        }
        if(n==k)return totalSum;
        int currSum=0;
        for(int i=0; i<n-k; i++){
           currSum+=cardPoints[i];
        }
        int ans = totalSum-currSum;
        for(int i=n-k; i<n; i++){
            currSum-= cardPoints[i-n+k];
            currSum += cardPoints[i];
            ans = max(ans,totalSum-currSum);
        }
        return ans;
    }
};