class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int tillMax = values[0];
        int maxScore = -1;
        for(int i=1; i<values.size(); i++){
            maxScore = max(maxScore, tillMax+values[i]-i);
            tillMax = max(tillMax,values[i]+i);
        }
        return maxScore;
    }
};