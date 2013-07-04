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
    TreeNode *GenTree(vector<int> &preorder, int pl, int pr, vector<int> &inorder, int il, int ir) {
        if (pl > pr) {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[pl]);
        int mid = il;
        while (inorder[mid] != preorder[pl]) {
            mid++;
        }
        int len = mid - il;
        root->left = GenTree(preorder, pl + 1, pl + len, inorder, il, mid - 1);
        root->right = GenTree(preorder, pl + len + 1, pr, inorder, mid + 1, ir);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (preorder.size() == 0) {
            return NULL;
        }
        return GenTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};