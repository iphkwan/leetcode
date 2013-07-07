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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode **pCur = &head;
        ListNode **helper = pCur;
        ListNode *entry = NULL;
        ListNode *dummy = NULL;
        bool flag;
        while (*pCur != NULL) {
            entry = *pCur;
            flag = false;
            helper = &(entry->next);
            while (*helper != NULL) {
                dummy = *helper;
                if (dummy->val != entry->val) {
                    break;
                }
                flag = true;
                *helper = dummy->next;
                delete dummy;
                dummy = NULL;
            }
            if (flag) {
                *pCur = entry->next;
                delete entry;
                entry = NULL;
            } else {
                pCur = &(entry->next);
            }
        }
        return head;
    }
};