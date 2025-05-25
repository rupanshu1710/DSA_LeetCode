class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1); // Initialize with -1, indicating no next greater or equal element
        stack<int> stack;
        set<int>st;
        for (int i=0; i<n; i++) {
            while (!stack.empty() && nums[i] >= nums[stack.top()]) {
                result[stack.top()] = i;
                stack.pop();
            }
            stack.push(i);
        }
        for(int i=0; i<n; i++){
            // cout<<result[i]<<" ";
            st.insert(result[i]);
            if(result[i]==-1)break;
            i = result[i]-1;
        }
        // cout<<endl;
        // for(int i/
        return st.size();
    }
};