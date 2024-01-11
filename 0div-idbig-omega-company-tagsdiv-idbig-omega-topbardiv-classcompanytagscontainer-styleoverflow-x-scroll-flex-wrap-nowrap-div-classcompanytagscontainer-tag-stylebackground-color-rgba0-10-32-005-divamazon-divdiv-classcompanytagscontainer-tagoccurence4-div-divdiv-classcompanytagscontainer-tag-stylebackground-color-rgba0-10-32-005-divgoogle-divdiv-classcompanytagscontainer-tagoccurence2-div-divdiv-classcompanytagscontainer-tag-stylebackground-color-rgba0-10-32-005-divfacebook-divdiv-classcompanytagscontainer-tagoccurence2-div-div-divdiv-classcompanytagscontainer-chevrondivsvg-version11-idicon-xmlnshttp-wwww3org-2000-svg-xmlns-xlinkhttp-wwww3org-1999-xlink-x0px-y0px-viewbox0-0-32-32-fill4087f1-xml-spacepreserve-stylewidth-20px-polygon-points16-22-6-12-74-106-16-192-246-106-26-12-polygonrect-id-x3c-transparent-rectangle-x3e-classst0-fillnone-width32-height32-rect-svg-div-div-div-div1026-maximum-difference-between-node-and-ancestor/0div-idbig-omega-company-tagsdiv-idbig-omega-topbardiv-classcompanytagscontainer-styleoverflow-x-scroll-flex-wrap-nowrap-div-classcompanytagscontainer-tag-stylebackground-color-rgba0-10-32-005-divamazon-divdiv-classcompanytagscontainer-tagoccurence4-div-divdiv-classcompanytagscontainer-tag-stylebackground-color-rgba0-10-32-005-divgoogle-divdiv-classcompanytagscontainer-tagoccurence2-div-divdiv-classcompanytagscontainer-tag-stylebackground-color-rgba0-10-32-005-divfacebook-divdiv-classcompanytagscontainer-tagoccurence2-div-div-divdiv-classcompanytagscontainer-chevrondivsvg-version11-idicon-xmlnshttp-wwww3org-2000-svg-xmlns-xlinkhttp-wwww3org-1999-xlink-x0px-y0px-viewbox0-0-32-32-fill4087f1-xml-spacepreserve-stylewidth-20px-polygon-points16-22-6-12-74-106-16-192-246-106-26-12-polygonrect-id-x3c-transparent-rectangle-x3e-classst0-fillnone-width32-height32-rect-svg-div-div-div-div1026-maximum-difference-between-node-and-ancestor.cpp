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
    int getAns(TreeNode* root, int mx, int mn){
        if(!root)return 0;
        mx = max(mx, root->val);
        mn = min(mn,root->val);
        int ans1 = getAns(root->left,mx,mn);
        int ans2 = getAns(root->right,mx,mn);
        return max(ans1,max(ans2,max(root->val-mn,mx-root->val)));
    }
    int maxAncestorDiff(TreeNode* root) {
        return getAns(root,0,INT_MAX);
        
    }
};