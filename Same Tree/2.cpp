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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode*> sp, sq;
        sp.push(p);
        sq.push(q);
        while(!sp.empty() && !sq.empty()) {
            TreeNode *np = sp.top();
            sp.pop();
            TreeNode *nq = sq.top();
            sq.pop();
            if(np == NULL || nq == NULL) {
                if(np != nq) 
                    return false;
            } else if(np->val != nq->val) { 
                return false;
            } else {
                sp.push(np->right);
                sp.push(np->left);
                sq.push(nq->right);
                sq.push(nq->left);
            }
        }
        if(!sp.empty() || !sq.empty())
            return false;
        return true;
    }
};