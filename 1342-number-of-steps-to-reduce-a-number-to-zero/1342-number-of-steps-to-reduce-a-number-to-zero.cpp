class Solution {
public:
    int numberOfSteps(int num) { // number of steps to reach 0
        if(num==0) return 0; // base case 1 
        if(num==1) return 1; // base case 2
        return numberOfSteps(num/2)+(num%2==0?1:2); // recursive case and add 1 if num is odd else add 2
    }
};