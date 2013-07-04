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
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return;
        }
        TreeNode *pLeft = root->left;
        TreeNode *pRight = root->right;
        flatten(pLeft);
        flatten(pRight);
        root->left = NULL;
        root->right = pLeft;
        TreeNode *pCnt = root;
        while (pCnt->right != NULL) {
            pCnt = pCnt->right;
        }
        pCnt->right = pRight;
        return;
    }
};