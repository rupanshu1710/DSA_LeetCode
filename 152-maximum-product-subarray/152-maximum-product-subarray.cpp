class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(); 
        int maxProd = nums[0];
        int currProdPos = nums[0];
        int currProdNeg = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]<0)swap(currProdPos, currProdNeg);
            currProdPos =  max(nums[i]*currProdPos,nums[i]);
            currProdNeg = min(nums[i]*currProdNeg,nums[i]);
            maxProd = max(maxProd,currProdPos);
        }
        return maxProd;
    }
};