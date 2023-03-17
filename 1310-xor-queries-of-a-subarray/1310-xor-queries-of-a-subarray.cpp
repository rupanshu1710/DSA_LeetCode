class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixXor;
        int xr = 0;
        for(int i=0; i<arr.size(); i++){
            xr ^= arr[i];
            prefixXor.push_back(xr);
        }
        vector<int>ans;
        for(auto i:queries){
            if(i[0]>0){
                ans.push_back(prefixXor[i[0]-1]^prefixXor[i[1]]);
            }
            else{
                ans.push_back(prefixXor[i[1]]);
            }
        }
        return ans;
    }
};