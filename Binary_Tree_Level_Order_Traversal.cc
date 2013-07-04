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
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        if (root == NULL) {
            return ans;
        }
        vector<int> tmp;
        queue<TreeNode *> q;
        queue<int> dep_que;
        q.push(root);
        dep_que.push(1);
        TreeNode *cntNode = NULL;
        int cntDepth, minDepth = 1;
        while (!q.empty()) {
            cntNode = q.front();
            q.pop();
            cntDepth = dep_que.front();
            dep_que.pop();
            if (cntDepth > minDepth) {
                minDepth = cntDepth;
                ans.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(cntNode->val);
            if (cntNode->left) {
                q.push(cntNode->left);
                dep_que.push(cntDepth + 1);
            }
            if (cntNode->right) {
                q.push(cntNode->right);
                dep_que.push(cntDepth + 1);
            }
        }
        if (tmp.size() > 0) {
            ans.push_back(tmp);
        }
        return ans;
    }
};