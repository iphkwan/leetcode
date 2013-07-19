/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool solve(ListNode ** &pCur, ListNode * head, ListNode * &ret, int cur, int k) {
        if (cur == k) {
            *pCur = head;
            pCur = &((*pCur)->next);
            ret = head->next;
            return true;
        }
        if (head->next && solve(pCur, head->next, ret, cur + 1, k)) {
            *pCur = head;
            pCur = &((*pCur)->next);
            return true;
        }
        return false;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret = NULL;
        ListNode **pCur = &ret;
        ListNode *nxt = NULL;
        while (head && solve(pCur, head, nxt, 1, k)) {
            head = nxt;
        }
        *pCur = head;
        return ret;
    }
};