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
    TreeNode *GenTree(vector<int> &inorder, int il, int ir, vector<int> &postorder, int pl, int pr) {
        if (il > ir) {
            return NULL;
        }
        TreeNode *root = new TreeNode(postorder[pr]);
        int mid = il;
        while (inorder[mid] != postorder[pr]) {
            mid++;
        }
        int len = mid - il;
        root->left = GenTree(inorder, il, mid - 1, postorder, pl, pl + len - 1);
        root->right = GenTree(inorder, mid + 1, ir, postorder, pl + len, pr - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.size() == 0) {
            return NULL;
        }
        return GenTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};