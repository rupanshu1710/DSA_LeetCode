class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = v1.size();
        int n2 = v2.size();
        int i=0,j=0;
        int num1 = 0;
        int num2 = 0;
        while(i<n1 || j<n2)
        {
            while(i<n1 && v1[i]!='.')
            {
                num1 = num1*10 + (v1[i++]-'0');
            }
            while(j<n2 && v2[j]!='.')
            {
                num2 = num2*10 + (v2[j++]-'0');
            }
            if(num1>num2) return 1;
            else if(num1 < num2) return -1;

            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};