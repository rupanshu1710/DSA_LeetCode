class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=1;
        int j=1;
        int cnt=0;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        while(j<flowerbed.size()-1){
            if(flowerbed[j]==0 && flowerbed[j+1]==0 && flowerbed[j-1]==0 ){
                cnt++;
                j+=2;
            }
            else j++;
        }
        // cout<<cnt<<endl;
        return cnt>=n;
    }
};