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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *entry = NULL;
        ListNode *pHead = NULL;
        ListNode *pTail = NULL;
        for (ListNode **pCnt = &head; *pCnt != NULL; ) {
            entry = *pCnt;
            if (entry->val < x) {
                *pCnt = entry->next;
                if (pHead == NULL) {
                    pHead = entry;
                    pTail = entry;
                } else {
                    pTail->next = entry;
                    pTail = pTail->next;
                }
            } else {
                pCnt = &(entry->next);
            }
        }
        if (pTail != NULL) {
            pTail->next = head;
            return pHead;
        }
        return head;
    }
};

//Another method using second level pointer
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret = NULL;
        ListNode **tail = &ret;
        ListNode **pHead = &head;
        ListNode *entry = NULL;
        for (ListNode **pCur = &head; *pCur; ) {
            entry = *pCur;
            if (entry->val < x) {
                *pCur = entry->next;
                *tail = entry;
                tail = &(entry->next);
            } else {
                pCur = &(entry->next);
            }
        }
        *tail = *pHead;
        return ret;
    }
};
