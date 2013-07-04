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
    vector<TreeNode *> GenTree(int l, int r) {
        vector<TreeNode *> ans;
        if (l > r) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = l; i <= r; i++) {
            vector<TreeNode *> Ltree = GenTree(l, i - 1);
            vector<TreeNode *> Rtree = GenTree(i + 1, r);
            for (int j = 0; j < Ltree.size(); j++) {
                for (int k = 0; k < Rtree.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = Ltree[j];
                    root->right = Rtree[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return GenTree(1, n);
    }
};