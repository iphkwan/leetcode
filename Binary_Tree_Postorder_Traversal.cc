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
    vector<int> postorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        TreeNode *dump = new TreeNode(0);
        dump->left = root;
        vector<int> ret;
        int L, R;
        TreeNode *cur = dump, *tmp = NULL, *helper = NULL;
        while (cur) {
            if (!cur->left) {
                cur = cur->right;
            } else {
                tmp = cur->left;
                while (tmp->right != NULL && tmp->right != cur)
                    tmp = tmp->right;
                if (tmp->right != cur) {
                    tmp->right = cur;
                    cur = cur->left;
                } else {
                    //print
                    L = ret.size();
                    helper = cur->left;
                    while (helper != cur) {
                        ret.push_back(helper->val);
                        helper = helper->right;
                    }
                    R = ret.size() - 1;
                    
                    //reverse
                    while (L < R) {
                        swap(ret[L++], ret[R--]);
                    }
                    
                    tmp->right = NULL;
                    cur = cur->right;
                }
            }
        }
        delete dump;
        return ret;
    }
};
