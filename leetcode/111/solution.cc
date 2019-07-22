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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                TreeNode* node = q.front();
                q.pop();
                if(!node->left && !node->right) {
                    return count;
                }
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            count++;
        }
        return count;
    }
};
