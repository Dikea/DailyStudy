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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            TreeNode *node = cur.first;
            if(res.size() < cur.second + 1) res.push_back(vector<int> {node->val});
            else res[cur.second].push_back(node->val);
            if(node->left) q.push(make_pair(node->left, cur.second + 1));
            if(node->right) q.push(make_pair(node->right, cur.second + 1));
        }
        return res;
    }
};
