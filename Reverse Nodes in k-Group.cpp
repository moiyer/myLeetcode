/*

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //2013/6/10 22:40:22
 //每次将最后一个插入到头之前
class Solution {
public:
	ListNode** recurssive(ListNode** pHead, int k, int* error)
	{
		if(k == 1)return &((*pHead)->next);

		ListNode** pTail = pHead;
		ListNode* tp;

		for(int i = 2; i <= k; ++i)
		{
			if((*pTail)->next == NULL){
				*error = -1;
				return NULL;
			}
			pTail = &((*pTail)->next);
		}

		tp = *pTail;
		*pTail = (*pTail)->next;
		tp->next = (*pHead);
		*pHead = tp;

		return recurssive(&((*pHead)->next), k - 1, error);
	}

    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || k <= 0)return NULL;

        ListNode **cur = &head;
        ListNode **pp;
        int error = 0;
        while(1)
        {
        	pp = recurssive(cur, k, &error);
        	if(error == -1)break;
        	cur = pp;
        }

        return head;
    }
};