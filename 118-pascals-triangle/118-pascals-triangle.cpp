class Solution {
public:
    vector<vector<int>> generate(int numRows){
        if(numRows==2) return {{1},{1,1}};
        if(numRows==1)return {{1}};
        vector<int> temp(numRows);
        vector<vector<int>> res = generate(numRows-1);
        temp[0]= 1;
        for(int i=1; i<numRows-1; i++){
            temp[i] = res[numRows-2][i-1] + res[numRows-2][i];
        }
        temp[numRows-1]=1;
        res.push_back(temp);
        return res;
    }
};