/*

Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.

*/
//23/07/2013 20:29
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
        if(head == NULL || (m == 0 && n == 0)return head;
        ListNode ** pCur = &head;
        ListNode ** pm, **pn;

        int i = 1;
        for(; i < m; ++i)
        	pCur = &((*pCur)->next);
        pm = pCur;
        for(; i < n; ++i)
        	pCur = &((*pCur)->next);
        pn = pCur;

        ListNode *tp;
        tp = *pn;
        *pn = *pm;
        *pm = tp;

        *tp = (*pn)->next;
        (*pn)->next = (*pm)->next;
        (*pm)->next = *tp;

        return head;
    }
};