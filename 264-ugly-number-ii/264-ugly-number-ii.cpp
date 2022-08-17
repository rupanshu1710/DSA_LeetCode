class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> t(n);
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;
        t[0] = 1;
        for(int i=1; i<n; i++){
            int twoMultiple = t[p2]*2;
            int threeMultiple = t[p3]*3;
            int fiveMultiple = t[p5]*5;
            t[i] = min(twoMultiple, min(threeMultiple, fiveMultiple));
            if(t[i]==twoMultiple)p2++;
            if(t[i]==threeMultiple)p3++;
            if(t[i]==fiveMultiple)p5++;
        }
        return t[n-1];
    }
};