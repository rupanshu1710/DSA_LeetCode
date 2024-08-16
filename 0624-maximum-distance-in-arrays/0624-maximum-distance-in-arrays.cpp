class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn1 = INT_MAX;
        int mn2 = INT_MAX;
        int mx1 = INT_MIN;
        int mx2 = INT_MIN;
        int cnt1=0, cnt2=0;
        int x=-1,y=-1;
        for(auto i:arrays){
            if(mn1>i[0]){
                mn2 = mn1;
                mn1 = i[0];
                x = cnt1;
            }
            else if(mn2>i[0]){
                mn2 = i[0];
            }
            cnt1++;
        }
        for(auto i:arrays){
            if(mx1<i[i.size()-1]){
                mx2 = mx1;
                mx1 = i[i.size()-1];
                y = cnt2;
            }
            else if(mx2<i[i.size()-1]){
                mx2 = i[i.size()-1];
            }
            cnt2++;
        }
        cout<<mx1<<" "<<mx2 <<" "<<mn1<<" "<<mn2<<endl;
        if(x!=y)return mx1 - mn1;
        return max(mx1 - mn2, mx2 - mn1);
    }
};