class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, right=0;
        int len = 0,n = s.size();
        vector<int> mpp(256,-1);
        while(right<n){
            if(mpp[s[right]]!=-1){
                left = max(mpp[s[right]] + 1,left);
            }
            mpp[s[right]] = right;
            len = max(right-left+1,len);
            right++;
        }
        return len;
    }
};