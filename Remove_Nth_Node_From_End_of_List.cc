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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode **pPre = &head;
        ListNode **pCur = &head;
        for (int i = 1; i < n; i++) {
            pPre = &((*pPre)->next);
        }
        while ((*pPre)->next) {
            pCur = &((*pCur)->next);
            pPre = &((*pPre)->next);
        }
        *pCur = (*pCur)->next;
        return head;
    }
};