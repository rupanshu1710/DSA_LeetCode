class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int,int>p;
        unordered_map<int,int>s;
        int n = nums.size();
        int a=0,k=0;
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                p[k] = nums[i];
                k++;
            }
            else{
                s[a]=nums[i];
                a++;
            }
        }
        vector<int>ans;
        for(int i=0; i<n/2; i++){
            ans.push_back(p[i]);
            ans.push_back(s[i]);
        }
        return ans;
    }
};