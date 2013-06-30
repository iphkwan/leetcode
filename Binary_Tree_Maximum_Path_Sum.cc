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
    int dfs (TreeNode *rt, int &ans) {
        ans = max(ans, rt->val);
        if (rt->left == NULL && rt->right == NULL)
            return rt->val;
        if (rt->left != NULL && rt->right == NULL) {
            int tmp = rt->val + dfs(rt->left, ans);
            ans = max(ans, tmp);
            return max(rt->val, tmp);
        }
        if (rt->left == NULL && rt->right != NULL) {
            int tmp = rt->val + dfs(rt->right, ans);
            ans = max(ans, tmp);
            return max(rt->val, tmp);
        }
        int tmp1 = dfs(rt->left, ans);
        int tmp2 = dfs(rt->right, ans);
        ans = max(ans, rt->val + max(tmp1, tmp2));
        ans = max(ans, rt->val + tmp1 + tmp2);
        return max(rt->val, rt->val + max(tmp1, tmp2));
    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ans = -0x7ffffff;
        dfs(root, ans);
        return ans;
    }
};