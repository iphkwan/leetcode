/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        RandomListNode *ret = NULL, *tmp = head, *entry = NULL;
        RandomListNode **pCur = &ret;
        while (tmp) {
            entry = tmp;
            tmp = tmp->next;
            entry->next = new RandomListNode(entry->label);
            entry->next->next = tmp;
        }
        
        tmp = head;
        while (tmp) {
            entry = tmp->next;
            if (tmp->random)
                entry->random = tmp->random->next;
            tmp = entry->next;
        }
        
        tmp = head;
        while (tmp) {
            entry = tmp->next;
            *pCur = entry;
            tmp->next = entry->next;
            tmp = tmp->next;
            pCur = &((*pCur)->next);
        }
        return ret;
    }
};
