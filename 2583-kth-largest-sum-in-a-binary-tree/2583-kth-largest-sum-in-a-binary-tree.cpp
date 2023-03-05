/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)return -1;
        priority_queue<long long>mxh;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            long long sum=0;
            int n = q.size();
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            mxh.push(sum);
        }
        while(mxh.size()>0 && k!=1){
            k--;
            mxh.pop();
        }
        if(mxh.size()>0)return mxh.top();
        return -1;
    }
};