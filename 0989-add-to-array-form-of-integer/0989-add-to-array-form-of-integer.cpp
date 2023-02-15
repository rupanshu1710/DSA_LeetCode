class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        string s  = to_string(k);
        vector<int>ans;
        int i=nums.size()-1;
        int j=s.size()-1;
        int carry=0;
        while(j>=0 && i>=0){
            int x = s[j] -'0' + nums[i]+carry;
            if(x>=10){
                ans.push_back(x%10);
                carry = 1;
            }
            else{
                ans.push_back(x);
                carry=0;
            }
            j--;
            i--;
        }
        while(j>=0){
            int x = s[j] -'0' +carry;
            if(x>=10){
                ans.push_back(x%10);
                carry = 1;
            }
            else{
                ans.push_back(x);
                carry=0;
            }
            j--;
        }
        while(i>=0){
            int x =  nums[i]+carry;
            if(x>=10){
                ans.push_back(x%10);
                carry = 1;
            }
            else{
                ans.push_back(x);
                carry=0;
            }
            i--;
        }
        if(carry==1)ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};