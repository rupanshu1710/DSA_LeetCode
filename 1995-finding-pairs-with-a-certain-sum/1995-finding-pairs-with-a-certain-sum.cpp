class FindSumPairs {
public:
    vector<int>temp1;
    vector<int>temp2;
    map<int,int>mp1;
    map<int,int>mp2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        temp1 = nums1;
        temp2 = nums2;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0; i<n2; i++){
            mp2[temp2[i]]++;
        }
        
    }
    
    void add(int index, int val) {
        mp2[temp2[index]]--;
        temp2[index] += val;
        mp2[temp2[index]]++;
    }
    
    int count(int tot) {
        int cnt=0;
        int n1 = temp1.size();
        for(int i=0; i<n1; i++){
            if(mp2.find(tot - temp1[i])!=mp2.end() && mp2[tot-temp1[i]]>0){
                cnt += mp2[tot - temp1[i]];
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */