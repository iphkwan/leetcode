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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (head == NULL || k == 0) {
            return head;
        }
        int len = 1;
        ListNode *pTail = head;
        while (pTail->next) {
            pTail = pTail->next;
            len++;
        }
        k = (len - (k % len)) % len;
        pTail->next = head;
        while (k--) {
            pTail = pTail->next;
        }
        head = pTail->next;
        pTail->next = NULL;
        return head;
    }
};