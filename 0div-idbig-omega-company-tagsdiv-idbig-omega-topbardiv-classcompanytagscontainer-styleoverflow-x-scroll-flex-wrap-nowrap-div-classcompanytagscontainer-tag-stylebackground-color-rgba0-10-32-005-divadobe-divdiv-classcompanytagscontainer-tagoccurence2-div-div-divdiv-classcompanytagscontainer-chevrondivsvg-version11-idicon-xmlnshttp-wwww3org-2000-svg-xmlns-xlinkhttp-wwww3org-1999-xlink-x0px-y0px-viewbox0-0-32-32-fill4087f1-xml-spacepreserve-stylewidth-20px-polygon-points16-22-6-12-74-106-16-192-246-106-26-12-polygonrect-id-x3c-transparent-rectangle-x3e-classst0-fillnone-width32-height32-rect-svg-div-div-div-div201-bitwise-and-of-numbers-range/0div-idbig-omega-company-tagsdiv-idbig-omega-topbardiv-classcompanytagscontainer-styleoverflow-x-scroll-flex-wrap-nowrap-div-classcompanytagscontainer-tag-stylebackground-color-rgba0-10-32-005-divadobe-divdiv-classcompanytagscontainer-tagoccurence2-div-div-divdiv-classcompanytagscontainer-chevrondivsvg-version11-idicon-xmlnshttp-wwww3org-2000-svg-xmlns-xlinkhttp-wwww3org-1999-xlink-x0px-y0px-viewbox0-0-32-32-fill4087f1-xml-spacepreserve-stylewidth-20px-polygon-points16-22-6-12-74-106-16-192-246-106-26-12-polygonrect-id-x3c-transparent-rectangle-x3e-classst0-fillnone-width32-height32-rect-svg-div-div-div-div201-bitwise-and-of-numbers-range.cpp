class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // cout<<(int)(log(left)/log(2))<<" "<<(int)(log(right)/log(2))<<endl;
        if(left==0 || left==right || left==right-1)return left&right;
        int ans=left;
        if((int)(log(left)/log(2))==(int)(log(right)/log(2))){
            for(long long int i=left+1; i<=right; i++){
                ans &= i;
            }
            return ans;
        }
        return 0;
    }
};