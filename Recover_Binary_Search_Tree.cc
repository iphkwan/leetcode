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

//O(1) space solution
//Based on Morris Traversal algorithm (Construct Threads Binary Tree)
class Solution {
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root)  return;
        TreeNode *pre = root;
        TreeNode *cur = root;
        TreeNode *tmp = NULL;
        TreeNode *One = NULL;
        TreeNode *Two = NULL;
        bool found = false;
        while (pre->left)   pre = pre->left;
        while (cur) {
            if (!cur->left) {
                if (cur->val < pre->val) {
                    if (!found) {
                        found = true;
                        One = pre;
                    }
                    Two = cur;
                }
                pre = cur;
                cur = cur->right;
            } else {
                tmp = cur->left;
                while (tmp->right && tmp->right != cur) {
                    tmp = tmp->right;
                }
                if (!tmp->right) {
                    tmp->right = cur;
                    cur = cur->left;
                } else {
                    tmp->right = NULL;
                    if (cur->val < pre->val) {
                        if (!found) {
                            found = true;
                            One = pre;
                        }
                        Two = cur;
                    }
                    pre = cur;
                    cur = cur->right;
                }
            }
        }
        if (found)  swap(One->val, Two->val);
    }
};
