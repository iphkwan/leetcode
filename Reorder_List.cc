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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        head = mergeList(head, reverseList(splitList(head)));
        return;
    }
private:
    ListNode *splitList(ListNode * head) {
        if (!head)
            return NULL;
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        return fast;
    }
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = NULL, *cur = head, *nxt = NULL;
        while (cur) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
    ListNode *mergeList(ListNode *ha, ListNode *hb) {
        ListNode *ret = NULL;
        ListNode **pCur = &ret;
        while (ha && hb) {
            *pCur = ha;
            pCur = &(ha->next);
            ha = ha->next;
            
            *pCur = hb;
            pCur = &(hb->next);
            hb = hb->next;
        }
        *pCur = ha;
        return ret;
    }
};
