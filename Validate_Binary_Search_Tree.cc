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
    bool judge(TreeNode *root, int &min_num) {
        if (root == NULL) {
            return true;
        }
        bool flag = judge(root->left, min_num);
        if (flag == false) {
            return false;
        }
        if (root->val <= min_num) {
            return false;
        }
        min_num = root->val;
        return judge(root->right, min_num);
    }
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int min_num = -0x7ffffff;
        return judge(root, min_num);
    }
};