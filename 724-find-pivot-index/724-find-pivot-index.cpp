class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum, rightSum, totalSum=0,index=-1;
        int size = nums.size();
        for(int i=0; i<size; i++){
            totalSum += nums[i];
        }
        rightSum = totalSum - nums[0];
         leftSum= 0;
        int i=0, j=size-1;
        while(i<j){
            if(leftSum == rightSum){
                return i;
                break;
            }
            else{
                leftSum += nums[i];
                rightSum -= nums[i+1];
                
            }
            i++;
            
        }
        if(leftSum==rightSum)return j;
        return index;
    }
};