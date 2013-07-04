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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        (this->ans).clear();
        this->tarSum = sum;
        if (root == NULL) {
            return this->ans;
        }
        vector<int> path;
        dfs(root, path, 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    int tarSum;
    void dfs(TreeNode *root, vector<int> &path, int total) {
        total += root->val;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL && total == this->tarSum) {
            (this->ans).push_back(path);
            path.pop_back();
            return;
        }
        if (root->left) {
            dfs(root->left, path, total);
        }
        if (root->right) {
            dfs(root->right, path, total);
        }
        path.pop_back();
        return;
    }
};