#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {

        vector<vector<int>> res = new vector<vector<int>>();
        vector<*TreeNode> levelNodesOld = vector<*TreeNode>();
        vector<*TreeNode> levelNodesNew = vector<*TreeNode>();
        bool left2right = true;

        levelNodesOld.push_back(root);

        while(true) {
            vector<int> level = vector<int>();
            if(left2right) {
                for(vector<int>::size_type i = 0; i != levelNodesOld.size(); ++i) {
                    level.clear();
                    node = levelNodesOld.at(i);
                    traverse(node, level, left2right);
                }
            } else {
                for(vector<int>::size_type i = levelNodesOld.size() - 1; i >= 0; --i) {
                    level.clear();
                    node = levelNodesOld.at(i);
                    traverse(node, level, left2right);
                }
            }
            left2right = !left2right;
            res.push_back(level);
            if(levelNodesNew.empty()) {
                break;
            }
            levelNodesOld.resize(levelNodesNew.size());
            levelNodesOld.assign(levelNodesNew.begin(), levelNodesNew.end());
            levelNodesNew.clear();
        }
        return res;
    }

    void traverse(TreeNode *root, vector<int> &level, bool left2right) {
        level.push_back(root->val);
        if(left2right) {
            if(root->left != NULL) {
                levelNodesNew.push_back(left);
            }
            if(root->right != NULL) {
                levelNodesNew.push_back(right);
            }
        } else {
            if(root->right != NULL) {
                levelNodesNew.push_back(right);
            }
            if(root->left != NULL) {
                levelNodesNew.push_back(left);
            }
        }
    }
};

int main() {

    return 0;
}
