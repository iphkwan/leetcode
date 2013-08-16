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


//O(1) space algorithm
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ret;
        TreeNode *pre = NULL;
        TreeNode *cur = root;
        while (cur) {
            if (!cur->left) {
                ret.push_back(cur->val);
                cur = cur->right;
            } else {
                pre = cur->left;
                while (pre->right && pre->right != cur)  pre = pre->right;
                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    ret.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ret;
    }
};
