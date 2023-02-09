class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0 ){
        return 1;}
        else if(n==1){
            return 0;
        }
        double x = log(n)/log(2);
        int cnt;
        cnt = x+1;
        cout<<cnt<<endl;
        int num =0;
        for(int i=0;i<cnt;i++){
           num += pow(2,i); 
        }
        cout<<num<<endl;
        return num^n;
    }
};
