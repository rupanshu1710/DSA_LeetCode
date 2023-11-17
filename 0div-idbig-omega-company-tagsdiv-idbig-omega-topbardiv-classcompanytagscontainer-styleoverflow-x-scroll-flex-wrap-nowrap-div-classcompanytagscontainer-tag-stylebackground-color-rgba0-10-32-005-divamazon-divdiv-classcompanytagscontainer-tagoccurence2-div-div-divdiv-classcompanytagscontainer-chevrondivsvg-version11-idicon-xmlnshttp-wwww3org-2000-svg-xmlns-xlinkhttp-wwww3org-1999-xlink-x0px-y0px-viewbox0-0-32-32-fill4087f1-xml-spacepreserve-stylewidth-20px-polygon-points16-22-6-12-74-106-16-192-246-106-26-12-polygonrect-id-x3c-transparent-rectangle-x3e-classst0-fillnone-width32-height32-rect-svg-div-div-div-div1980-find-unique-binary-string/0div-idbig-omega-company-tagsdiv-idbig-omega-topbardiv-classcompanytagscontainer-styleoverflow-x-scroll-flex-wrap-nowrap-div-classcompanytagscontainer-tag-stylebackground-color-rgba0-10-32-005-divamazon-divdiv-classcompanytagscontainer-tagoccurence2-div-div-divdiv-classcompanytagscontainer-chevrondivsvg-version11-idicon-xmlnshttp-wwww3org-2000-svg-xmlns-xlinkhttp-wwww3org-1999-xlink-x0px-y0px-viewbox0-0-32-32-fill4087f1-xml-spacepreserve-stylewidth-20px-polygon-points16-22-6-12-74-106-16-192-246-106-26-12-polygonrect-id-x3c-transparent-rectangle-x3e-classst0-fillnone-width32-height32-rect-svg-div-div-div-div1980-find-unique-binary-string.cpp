class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        sort(nums.begin(),nums.end());
        int x=0;
        for(auto i:nums){
            int temp=0;
            int j=i.size()-1;
            for(auto it:i){
                if(it=='1')temp += pow(2,j);
                j--;
            }
            if(temp==x)x++;
            else break;
        }
        // cout<<x<<endl;
        string ans="";
        int n = nums[0].size();
        for(int i=0; i<nums[0].size(); i++){
            if(x%2==0){
                ans += '0';
            }
            else ans += '1';
            x = x/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};