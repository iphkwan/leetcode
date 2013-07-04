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
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL) {
            return 0;
        }
        queue<TreeNode *> que;
        queue<int> dep_que;
        que.push(root);
        dep_que.push(1);
        TreeNode *cntNode;
        int cntDepth = -1;
        while (!que.empty()) {
            cntNode = que.front();
            que.pop();
            cntDepth = dep_que.front();
            dep_que.pop();
            if (cntNode->left == NULL && cntNode->right == NULL) {
                return cntDepth;
            }
            if (cntNode->left) {
                que.push(cntNode->left);
                dep_que.push(cntDepth + 1);
            }
            if (cntNode->right) {
                que.push(cntNode->right);
                dep_que.push(cntDepth + 1);
            }
        }
        return cntDepth;
    }
};