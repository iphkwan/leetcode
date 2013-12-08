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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *ret = NULL, *tmp = head, *nxt = NULL;
        ListNode **pCur = &ret;
        while (tmp) {
            pCur = &ret;
            while (*pCur && (*pCur)->val <= tmp->val)
                pCur = &((*pCur)->next);
            nxt = tmp->next;
            tmp->next = *pCur;
            *pCur = tmp;
            tmp = nxt;
        }
        return ret;
    }
};
