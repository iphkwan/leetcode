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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = n - m + 1;
        if (len <= 1) {
            return head;
        }
        ListNode **ppHead = &head;
        for (int i = 1; i < m; i++) {
             ppHead = &((*ppHead)->next);
        }
        ListNode *pCur = *ppHead;
        ListNode *pPre = NULL;
        ListNode *pNxt = NULL;
        while (len--) {
            pNxt = pCur->next;
            pCur->next = pPre;
            pPre = pCur;
            pCur = pNxt;
        }
        (*ppHead)->next = pCur;
        *ppHead = pPre;
        return head;
    }
};