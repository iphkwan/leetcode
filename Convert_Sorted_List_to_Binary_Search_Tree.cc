/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int GetListLen(ListNode *pt) {
        int len = 0;
        while (pt != NULL) {
            len++;
            pt = pt->next;
        }
        return len;
    }
    TreeNode *GenTree(ListNode *pCnt, int l, int r) {
        if (l > r) {
            return NULL;
        }
        int mid = l + (r - l) / 2;
        ListNode *pt = pCnt;
        for (int i = l; i < mid; i++) {
            pt = pt->next;
        }
        TreeNode *root = new TreeNode(pt->val);
        root->left = GenTree(pCnt, l, mid - 1);
        root->right = GenTree(pt->next, mid + 1, r);
        return root;
    }
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL) {
            return NULL;
        }
        int len = GetListLen(head);
        return GenTree(head, 0, len - 1);
    }
};