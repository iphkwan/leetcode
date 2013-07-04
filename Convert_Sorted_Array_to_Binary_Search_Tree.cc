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
    TreeNode *GenTree(vector<int> &num, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int mid = l + (r - l) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = GenTree(num, l, mid - 1);
        root->right = GenTree(num, mid + 1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() == 0) {
            return NULL;
        }
        return GenTree(num, 0, num.size() - 1);
    }
};