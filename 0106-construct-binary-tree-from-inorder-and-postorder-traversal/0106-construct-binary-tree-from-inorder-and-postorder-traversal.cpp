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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, map<int,int>&mp, int is, int ps, int ie, int pe){
        if(is>ie || ps>pe)return NULL;
        int rootdata = postorder[pe];
        TreeNode* node = new TreeNode(rootdata);
        int idx = mp[rootdata];
        node->left = helper(inorder,postorder,mp,is,ps,idx-1,ps+idx-is-1);
        node->right = helper(inorder,postorder,mp,idx+1,ps + idx-is,ie,pe-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n!=postorder.size())return NULL;
        map<int,int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        // int n = inorder.size();
        int temp = postorder[n-1];
        return helper(inorder,postorder,mp,0,0,n-1,n-1);
    }
};