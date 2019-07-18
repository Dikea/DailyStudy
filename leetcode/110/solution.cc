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
    bool isBalanced(TreeNode* root) {
        int res = dfs(root);
        return res == -1 ? false : true;
    }

private:
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int leftDepth = dfs(root->left);
        int rightDepth = dfs(root->right);
        if(leftDepth == -1 || rightDepth == -1) return -1;
        if(abs(leftDepth - rightDepth) > 1) return -1;
        return max(leftDepth, rightDepth) + 1;
    }
};
