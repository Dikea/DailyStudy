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
    bool isValidBST(TreeNode* root) {
        return isValid(root, NULL, NULL);
    }

private:
    bool isValid(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
        if(root == NULL) return true;
        if(minNode && root->val <= minNode->val) return false;
        if(maxNode && root->val >= maxNode->val) return false;
        return isValid(root->left, minNode, root) && isValid(root->right, root, maxNode);
    }
};
