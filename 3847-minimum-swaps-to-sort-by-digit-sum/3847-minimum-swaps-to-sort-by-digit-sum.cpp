class Solution {
public:
int minswaps(vector<int>& A, vector<int>& B) {
    if (A == B) return 0; // Early exit if arrays are already identical
    cout<<endl;
    // for(int i=0; i<A/
    // for(int i=0; i<B.size(); i++){
    //     cout<<B[i]<<" ";
    // }
    // cout<<endl;
    unordered_map<int, int> posB;
    for (int i = 0; i < B.size(); ++i) {
        posB[B[i]] = i; // Map element to its index in B
    }

    int n = A.size();
    vector<int> permutation(n);
    for (int i = 0; i < n; ++i) {
        permutation[i] = posB[A[i]]; // Create permutation array
    }

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            int cycleLen = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = permutation[j];
                cycleLen++;
            }
            swaps += (cycleLen - 1); // Add swaps for this cycle
        }
    }

    return swaps;
}
    int minSwaps(vector<int>& nums) {
        map<int,int>mp;
        int n = nums.size();
        vector<int>nums1 = nums;
        for(int i=0; i<n; i++){
            mp[i] = nums[i];
        }
        sort(nums.begin(),nums.end());
        map<int,vector<int>>mp1;
        vector<int>temp;
        for(int i=0; i<n; i++){
            string s = to_string(nums[i]);
            int sum  = 0;
            for(auto it:s){
                sum += it-'0';
            }
            mp1[sum].push_back(nums[i]);
        }
        for(auto i:mp1){
            for(auto j:i.second){
                // cout<<j<<endl;
                temp.push_back(j);
                // cout<<temp.back()<<endl;
            }
        }

        map<int,int>mp2;
        int x = 0;
        for(auto i:temp){
            // cout<<i<<endl;
            mp2[i] = x;
            x++;
        }
        int ans = 0;
        // for(int i=0; i<n; i++){
        //     // cout<<temp[i]<<" ";
        // }
        return minswaps(temp,nums1);
        cout<<temp.size()<<endl;
        for(int i=0; i<n; i++){
            // cout<<temp[i]<<" "<<i<<" ";
            int idx = mp[i];
            int x = temp[i];
            int a  = i;
            int b = mp2[idx];
            int y = mp2[idx];
            if(mp2[idx]!=i){
                cout<<temp[i]<<" "<<temp[mp2[idx]]<<endl;
                swap(temp[i],temp[mp2[idx]]);
                mp2[y] = a;
                mp2[x] = b;
                ans++;
            }
        }
        return ans;
    }
};