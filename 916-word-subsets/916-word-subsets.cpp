class Solution {
public:
    void calculateFrq(int *arr, string &s){
        for(auto &i:s){
            arr[i-'a']++;
        }
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        int totalFrq[26] = {0};
        for(auto i:words2){
            int frq[26] =  {0};
            calculateFrq(frq,i);
            for(int j=0; j<26; j++){
                totalFrq[j] = max(totalFrq[j], frq[j]);
            }
        }
        for(auto i:words1){
            int frq[26] = {0};
            calculateFrq(frq,i);
            int j;
            for(j=0; j<26; j++){
                if(frq[j]<totalFrq[j])break;
            }
            if(j==26)ans.push_back(i);
        }
        return ans;
    }
};