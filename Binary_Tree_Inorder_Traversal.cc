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
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        stack<TreeNode *> st;
        stack<bool> flag;
        st.push(root);
        flag.push(false);
        TreeNode *cntNode = NULL;
        bool state;
        while (!st.empty()) {
            cntNode = st.top();
            state = flag.top();
            flag.pop();
            if (state == false) {
                flag.push(true);
                if (cntNode->left) {
                    st.push(cntNode->left);
                    flag.push(false);
                }
            } else {
                st.pop();
                ans.push_back(cntNode->val);
                if (cntNode->right) {
                    st.push(cntNode->right);
                    flag.push(false);
                }
            }
        }
        return ans;
    }
};