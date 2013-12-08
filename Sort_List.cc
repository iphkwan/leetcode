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
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head || !head->next)
            return head;
        ListNode *fast = head, *slow = head, *tmp = NULL;
        
        //split
        while (fast && fast->next) {
            fast = fast->next->next;
            tmp = slow;
            slow = slow->next;
        }
        tmp->next = NULL;
        
        //recursion
        head = sortList(head);
        slow = sortList(slow);
        
        //merge
        ListNode *ret = NULL;
        ListNode **pCur = &ret;
        while (head && slow) {
            if (head->val <= slow->val) {
                *pCur = head;
                head = head->next;
            } else {
                *pCur = slow;
                slow = slow->next;
            }
            pCur = &((*pCur)->next);
        }
        if (head)   *pCur = head;
        if (slow)    *pCur = slow;
        return ret;
    }
};
