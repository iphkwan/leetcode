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
    vector<int> preorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> ret;
        TreeNode *cur = root, *tmp = NULL;
        while (cur) {
            if (!cur->left) {
                ret.push_back(cur->val);
                cur = cur->right;
            } else {
                tmp = cur->left;
                while (tmp->right && tmp->right != cur)
                    tmp = tmp->right;
                if (!tmp->right) {
                    tmp->right = cur;
                    ret.push_back(cur->val);
                    cur = cur->left;
                } else {
                    tmp->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return ret;
    }
};
