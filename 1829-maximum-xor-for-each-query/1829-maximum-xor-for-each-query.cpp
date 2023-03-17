class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>prefixXor;
        int xr = 0;
        for(int i=0; i<nums.size(); i++){
            xr ^= nums[i];
            prefixXor.push_back(xr);
        }
        vector<int>bit(maximumBit,1);
        vector<int>ans;
        for(int i=0; i<nums.size(); i++){
            int temp = prefixXor[i];
            // cout<<temp<<" ";
            int res=0;
            for(int j=0; j<maximumBit; j++){
                if(!(temp&1)){
                    res += pow(2,j);
                }
                temp = temp>>1;
                // cout<<temp<<" ";
            }
            // cout<<endl;
            ans.push_back(res);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};