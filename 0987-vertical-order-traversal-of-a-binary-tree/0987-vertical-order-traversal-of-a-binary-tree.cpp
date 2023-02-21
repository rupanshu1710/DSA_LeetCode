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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        // mp[0] = root->val;
        while(!q.empty()){
            int size = q.size();
            map<int,vector<int>>mp1;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                int lvl = q.front().second;
                q.pop();
                mp1[lvl].push_back(node->val);
                if(node->left){
                    q.push({node->left,lvl-1});
                }
                if(node->right){
                    q.push({node->right,lvl+1});
                }
            }
            for(auto i:mp1){
                sort(i.second.begin(),i.second.end());
                for(auto it:i.second){
                    mp[i.first].push_back(it);
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};