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
    bool judge(TreeNode *root, int &depth) {
        if (root == NULL) {
            depth = 0;
            return true;
        }
        int leftHeight, rightHeight;
        if (judge(root->left, leftHeight) && judge(root->right, rightHeight)) {
            if (leftHeight > rightHeight + 1 || rightHeight > leftHeight + 1)
                return false;
            if (leftHeight > rightHeight) {
                depth = leftHeight + 1;
            } else {
                depth = rightHeight + 1;
            }
            return true;
        }
        return false;
    }
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }
        int tmp = 0;
        return judge(root, tmp);
    }
};