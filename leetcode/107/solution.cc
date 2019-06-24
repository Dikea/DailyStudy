/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> tmp(size);
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                tmp[i] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(tmp);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
