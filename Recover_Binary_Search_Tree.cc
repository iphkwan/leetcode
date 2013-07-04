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
    void dfs(TreeNode * &pre, TreeNode *cnt, TreeNode * &p, TreeNode * &q) {
        if (cnt == NULL) {
            return;
        }
        dfs(pre, cnt->left, p, q);
        if (pre != NULL && pre->val > cnt->val) {
            if (p == NULL) {
                p = pre;
            }
            q = cnt;
        }
        pre = cnt;
        dfs(pre, cnt->right, p, q);
    }
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeNode *pre = NULL, *p = NULL, *q = NULL;
        dfs(pre, root, p, q);
        if (p != NULL && q != NULL) {
            int tmp = p->val;
            p->val = q->val;
            q->val = tmp;
        }
    }
};