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
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret = NULL;
        ListNode **pCur = &ret;
        ListNode *nxt = NULL;
        while (head && head->next) {
            nxt = head->next->next;
            *pCur = head->next;
            pCur = &((*pCur)->next);
            *pCur = head;
            pCur = &((*pCur)->next);
            head = nxt;
        }
        *pCur = head;
        return ret;
    }
};