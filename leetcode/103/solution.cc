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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToright = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> tmp(size);
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                int index = leftToright ? i : size - 1 - i;
                tmp[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            leftToright = !leftToright;
            res.push_back(tmp);
        }
        return res;
    }
};
