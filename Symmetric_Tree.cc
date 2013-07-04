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
    bool judge(TreeNode *lchild, TreeNode *rchild) {
        if (lchild == NULL || rchild == NULL) {
            if (lchild == NULL && rchild == NULL) {
                return true;
            }
            return false;
        }
        if (lchild->val != rchild->val) {
            return false;
        }
        return judge(lchild->left, rchild->right) && judge(lchild->right, rchild->left);
    }
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return true;
        }
        return judge(root->left, root->right);
    }
};