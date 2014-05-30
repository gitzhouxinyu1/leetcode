/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if(!root) return 0;
        stack<TreeNode*> s;
        root->val = 1;
        int maxD = root->val;
        s.push(root);
        while(!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if(node->right) {
               node->right->val = 1 + node->val;
               maxD = max(maxD, node->right->val);
               s.push(node->right);
            }
            if(node->left) {
               node->left->val = 1 + node->val;
               maxD = max(maxD, node->left->val);
               s.push(node->left);
            }
        }
        return maxD;
    }
};