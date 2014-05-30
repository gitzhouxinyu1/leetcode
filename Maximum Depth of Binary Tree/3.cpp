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
        queue<TreeNode*> q;
        root->val = 1;
        int maxD = root->val;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if(node->left) {
               node->left->val = 1 + node->val;
               maxD = max(maxD, node->left->val);
               q.push(node->left);
            }
            if(node->right) {
               node->right->val = 1 + node->val;
               maxD = max(maxD, node->right->val);
               q.push(node->right);
            }
        }
        return maxD;
    }
};