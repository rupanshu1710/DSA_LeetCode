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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)return NULL;
        TreeNode* l=NULL;
        TreeNode* r=NULL;
        
        if(root->val>val){
            l=searchBST(root->left,val);
        }else if(root->val<val){
            r=searchBST(root->right,val);
        }else{
            return root;
        }
        if(l){
            return l;
        }else{
            return r;
        }
    }
};