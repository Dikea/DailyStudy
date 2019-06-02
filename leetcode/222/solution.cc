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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode *l = root, *r = root;
        int lCnt = 0, rCnt=0;
        while(l) {
            l = l->left;
            lCnt++;
        }
        while(r) {
            r = r->right;
            rCnt++;
        }
        if(lCnt == rCnt) return pow(2, lCnt) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
