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
    int findSecondMinimumValue(TreeNode* root) {
        traverse(root, root->val);
        return res;
    }

private:
    int res = -1;
    void traverse(TreeNode* root, int key) {
        if(!root) return ;
        if(root->val > key) {
            if(res == -1) res = root->val;
            if(res > root->val) res = root->val;
        }
        traverse(root->left, key);
        traverse(root->right, key);
    }
};
