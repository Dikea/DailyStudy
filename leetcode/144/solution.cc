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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        while(root || !st.empty()) {
            while(root) {
                st.push(root);
                res.push_back(root->val);
                root = root->left;
            }
            root = st.top();
            st.pop();
            root = root->right;
        }
        return res;
    }
};
