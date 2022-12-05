class Solution {
public:
    int maxSatisfaction(vector<int>& s) {
        int score = 0;
        int i=0;
        int sum=0;
        sort(s.begin(),s.end());
        for(int i=0; i<s.size(); i++){
            score += (i+1)*s[i];
            sum += s[i];
        }
        while(i<s.size()){
            if(score < score - sum){
                score -= sum;
                sum -= s[i];
                s.erase(s.begin()+i);
                i--;
            }
            i++;
        }
        int ans=0;
        for(int i=0; i<s.size(); i++){
            ans += (i+1)*s[i];
        }
        return ans;
    }
};