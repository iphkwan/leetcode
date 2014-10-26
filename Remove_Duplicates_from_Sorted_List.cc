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
        ListNode *pPre = NULL;
        ListNode *entry = NULL;
        while (*pCur != NULL) 
            entry = *pCur;
            if (pPre != NULL && pPre->val == entry->val) {
                *pCur = entry->next;
                delete entry;
                entry = NULL;
            } else {
                pCur = &(entry->next);
                pPre = entry;
            }
        }
        return head;
    }
};
class Solution2{
 public:
 ListNode *deleteDuplicates(ListNode *head){
   ListNode *pcur=head;
   ListNode *pnext=head;
   if(head==NULL||head->next==NULL){
   return head;
   }
   while(pcur->next!=NULL){
      pnext=pcur->next;
      if(pnext->val==pcur->val){
         pcur->next=pnext->next;
      }else{
      pcur=pcur->next;
      }
   }
   return head;
 }
};
