/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (root == NULL)
            return;
        TreeLinkNode *p = root;
        TreeLinkNode *cntNode = NULL;
        TreeLinkNode *nxtLevel = NULL;
        while (p) {
            if (p->left) {
                if (cntNode)
                    cntNode->next = p->left;
                cntNode = p->left;
                if (nxtLevel == NULL)
                    nxtLevel = cntNode;
            }
            if (p->right) {
                if (cntNode)
                    cntNode->next = p->right;
                cntNode = p->right;
                if (nxtLevel == NULL)
                    nxtLevel = cntNode;
            }
            p = p->next;
        }
        connect(nxtLevel);
    }
};



//Add non-recursive method.
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeLinkNode *pCur = root, *pBegin = NULL;
        TreeLinkNode **pTail = &pBegin;
        while (pCur != NULL) {
            while (pCur != NULL) {
                if (pCur->left) {
                    if (!pBegin)    pBegin = pCur->left;
                    else    *pTail = pCur->left;
                    pTail = &((*pTail)->next);
                }
                if (pCur->right) {
                    if (!pBegin)    pBegin = pCur->right;
                    else    *pTail = pCur->right;
                    pTail = &((*pTail)->next);
                }
                pCur = pCur->next;
            }
            pCur = pBegin;
            pBegin = NULL;
            pTail = &pBegin;
        }
        return;
    }
};
