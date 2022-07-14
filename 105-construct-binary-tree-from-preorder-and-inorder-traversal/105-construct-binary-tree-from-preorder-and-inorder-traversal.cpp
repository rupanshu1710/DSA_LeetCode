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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0 )return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int index1 = 0;
        while(inorder[index1]!=preorder[0]){
            index1++;
        }
        //index2 = index1+1;
        vector<int>inorder1;
        for(int i=0; i<index1; i++){
            inorder1.push_back(inorder[i]);
        }
        vector<int>preorder1;
        for(int i=1; i<=index1; i++){
            preorder1.push_back(preorder[i]);
        }
        vector<int>inorder2;
        for(int i=index1+1; i<inorder.size(); i++){
            inorder2.push_back(inorder[i]);
        }
        vector<int>preorder2;
        for(int i=index1+1; i<preorder.size(); i++){
            preorder2.push_back(preorder[i]);
        }
        root->left = buildTree(preorder1,inorder1);
        root->right = buildTree(preorder2,inorder2);
        return root;
        
    }
};