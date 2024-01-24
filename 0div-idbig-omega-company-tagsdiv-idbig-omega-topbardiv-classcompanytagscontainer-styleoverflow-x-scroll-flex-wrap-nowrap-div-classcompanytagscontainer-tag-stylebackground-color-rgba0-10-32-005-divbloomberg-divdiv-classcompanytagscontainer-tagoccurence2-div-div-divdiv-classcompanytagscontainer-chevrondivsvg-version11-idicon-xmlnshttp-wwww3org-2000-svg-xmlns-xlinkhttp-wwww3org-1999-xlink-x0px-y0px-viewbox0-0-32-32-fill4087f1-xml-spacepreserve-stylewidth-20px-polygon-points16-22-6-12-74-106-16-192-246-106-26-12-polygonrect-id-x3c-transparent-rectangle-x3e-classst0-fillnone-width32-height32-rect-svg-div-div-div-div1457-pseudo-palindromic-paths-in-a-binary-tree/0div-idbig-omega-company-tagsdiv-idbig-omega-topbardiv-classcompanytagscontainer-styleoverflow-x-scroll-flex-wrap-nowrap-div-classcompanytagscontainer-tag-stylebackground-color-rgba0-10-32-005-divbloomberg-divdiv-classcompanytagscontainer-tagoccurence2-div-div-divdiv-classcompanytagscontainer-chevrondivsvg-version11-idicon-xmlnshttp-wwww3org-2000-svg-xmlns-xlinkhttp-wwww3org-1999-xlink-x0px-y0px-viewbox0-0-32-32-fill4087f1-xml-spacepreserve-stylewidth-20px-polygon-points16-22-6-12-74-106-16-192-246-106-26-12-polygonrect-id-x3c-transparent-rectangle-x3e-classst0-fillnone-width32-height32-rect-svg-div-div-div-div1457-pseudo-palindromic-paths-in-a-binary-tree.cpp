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
    int getAns(TreeNode* root, vector<int>&mp){
        if(!root->left && !root->right){
            int flag=1;
            int cnt=0;
            for(auto i:mp){
                if(i%2){
                    cnt++;
                }
                if(cnt>1)break;
            }
            cout<<cnt<<" "<<endl;
            if(cnt>1)return 0;
            else return 1;
        }
        int ans1=0,ans2=0;
        if(root->left){
            vector<int>mp1 = mp;
            mp1[root->left->val-1]++;
            ans1 = getAns(root->left,mp1);
        }
        if(root->right){
            vector<int>mp2 = mp;
            mp2[root->right->val-1]++;
            ans2 = getAns(root->right,mp2);
        }
        return ans1 + ans2;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>mp(10,0);
        mp[root->val-1]++;
        return getAns(root,mp);
    }
};