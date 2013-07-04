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
    bool dfs(TreeNode *root, int total) {
        total -= root->val;
        if (root->left == NULL && root->right == NULL) {
            if (total == 0) {
                return true;
            }
            return false;
        }
        if (root->left && dfs(root->left, total)) {
            return true;
        }
        if (root->right && dfs(root->right, total)) {
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return false;
        }
        return dfs(root, sum);
    }
};