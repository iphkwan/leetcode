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
    int ans;
    void dfs(int cnt, TreeNode *rt) {
        cnt = 10 *cnt + rt->val;
        if (rt->left == NULL && rt->right == NULL) {
            ans += cnt;
            return;
        }
        if (rt->left != NULL)
            dfs (cnt, rt->left);
        if (rt->right != NULL)
            dfs (cnt, rt->right);
    }
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return 0;
        ans = 0;
        dfs(0, root);
        return ans;
    }
};