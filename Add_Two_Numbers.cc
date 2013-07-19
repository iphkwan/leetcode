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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret = NULL;
        ListNode **pCur = &ret;
        int nxt = 0;
        while (l1 && l2) {
            *pCur = new ListNode((l1->val + l2->val + nxt) % 10);
            nxt = (l1->val + l2->val + nxt) / 10;
            pCur = &((*pCur)->next);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            *pCur = new ListNode((l1->val + nxt) % 10);
            nxt = (l1->val + nxt) / 10;
            pCur = &((*pCur)->next);
            l1 = l1->next;
        }
        while (l2 != NULL) {
            *pCur = new ListNode((l2->val + nxt) % 10);
            nxt = (l2->val + nxt) / 10;
            pCur = &((*pCur)->next);
            l2 = l2->next;
        }
        if (nxt > 0) {
            *pCur = new ListNode(nxt);
        }
        return ret;
    }
};