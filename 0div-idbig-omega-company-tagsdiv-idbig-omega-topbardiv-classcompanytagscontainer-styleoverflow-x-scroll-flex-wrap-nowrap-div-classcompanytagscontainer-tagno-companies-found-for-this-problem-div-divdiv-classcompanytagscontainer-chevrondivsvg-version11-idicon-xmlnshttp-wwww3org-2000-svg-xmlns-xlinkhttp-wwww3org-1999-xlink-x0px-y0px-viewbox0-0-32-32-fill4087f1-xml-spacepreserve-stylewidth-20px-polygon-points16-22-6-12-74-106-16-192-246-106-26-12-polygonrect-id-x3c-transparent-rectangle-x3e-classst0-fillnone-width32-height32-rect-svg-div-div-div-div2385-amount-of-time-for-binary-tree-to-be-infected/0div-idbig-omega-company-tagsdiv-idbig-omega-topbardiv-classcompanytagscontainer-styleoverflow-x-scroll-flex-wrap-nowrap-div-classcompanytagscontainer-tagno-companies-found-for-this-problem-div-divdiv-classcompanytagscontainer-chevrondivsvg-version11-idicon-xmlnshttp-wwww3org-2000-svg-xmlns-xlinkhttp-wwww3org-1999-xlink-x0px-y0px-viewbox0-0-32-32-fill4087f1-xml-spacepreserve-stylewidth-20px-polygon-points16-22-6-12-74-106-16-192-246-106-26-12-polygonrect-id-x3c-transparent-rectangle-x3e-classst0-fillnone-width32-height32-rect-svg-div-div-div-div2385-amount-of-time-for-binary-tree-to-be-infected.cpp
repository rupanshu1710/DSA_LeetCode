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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*>mpp;
        map<TreeNode*,int>vis   ;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* temp;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val==start)temp = node;
            q.pop();
            if(node->left){
                q.push(node->left);
                mpp[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                mpp[node->right] = node;
            }
        }
        queue<TreeNode*> q1;
        q1.push(temp);
        vis[temp]++;
        int ans=0;
        while(!q1.empty()) {
            int sz = q1.size();
            bool flag = 0; 
            for(int i = 0;i<sz;i++) {
                auto node = q1.front();
                q1.pop();
                if(node->left && !vis[node->left]) {
                    flag = 1; 
                    vis[node->left] = 1; 
                    q1.push(node->left); 
                }
                if(node->right && !vis[node->right]) {
                    flag = 1; 
                    vis[node->right] = 1; 
                    q1.push(node->right); 
                }

                if(mpp[node] && !vis[mpp[node]]) {
                    flag = 1; 
                    vis[mpp[node]] = 1; 
                    q1.push(mpp[node]); 
                } 
            }
            if(flag) ans++; 
        }
        // while(!q1.empty()){
        //     TreeNode* node = q1.front();
        //     q1.pop();
        //     bool flag=0;
        //     if(node->left && mp1.find(node->left)==mp1.end()){
        //         flag=1;
        //         mp1[node->left]++;
        //         q1.push(node->left);
        //     }
        //     if(node->right && mp1.find(node->right)==mp1.end()){
        //         flag=1;
        //         mp1[node->right]++;
        //         q1.push(node->right);
        //     }
        //     if(mp.find(node)!=mp.end() && mp1.find(mp[node])==mp1.end()){
        //         flag=1;
        //         mp1[mp[node]]++;
        //         q1.push(mp[node]);
        //     }
        //     if(flag)ans++;
        //     // mp1[node]++;
        // }
        return ans;
        
    }
};