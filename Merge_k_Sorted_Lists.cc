/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct cmp {
    bool operator () (ListNode *x, ListNode *y) {
        return x->val > y->val;
    }
};
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *ret = NULL;
        ListNode **pCur = &ret;
        ListNode *tmp = NULL;
        if (lists.size() == 0) {
            return ret;
        }
        priority_queue<ListNode *, vector<ListNode *>, cmp> que;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                que.push(lists[i]);
            }
        }
        while (!que.empty()) {
            tmp = que.top();
            que.pop();
            *pCur = tmp;
            pCur = &((*pCur)->next);
            if (tmp->next != NULL) {
                que.push(tmp->next);
            }
        }
        return ret;
    }
};