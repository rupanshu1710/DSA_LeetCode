class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        int mn = *min_element(nums.begin(),nums.end());
        if(mx==mn)return 1;
        if(nums.size()==1 || nums.size()==2)return nums.size();
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                nums.erase(nums.begin()+i);
                i--;
            }
        }
        int t[nums.size()][2];
        t[0][0] = 1;
        t[0][1] = 0;
        t[1][0] = 2;
        t[1][1] = (nums[1]-nums[0])>0?1:-1;
        for(int i=2; i<nums.size(); i++){
            if((nums[i]-nums[i-1])*t[i-1][1]<0)
            {
                t[i][0] = 1 + t[i-1][0];
            }
            else t[i][0] = t[i-1][0];
            t[i][1] = (nums[i]-nums[i-1])>0?1:-1;
        }
        return t[nums.size()-1][0];
    }
};