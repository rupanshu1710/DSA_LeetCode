class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s;
        vector<int> ans;
        int n1 = nums1.size();
        int n2 = nums2.size();
        for(int i=0; i<n1; i++)
        {
            s.insert(nums1[i]);
        }
        for(int i=0; i<n2; i++)
        {
            if(s.find(nums2[i]) != s.end())
            {
                ans.push_back(nums2[i]);
                s.erase(nums2[i]);
            }
        }
        return ans;
    }
};