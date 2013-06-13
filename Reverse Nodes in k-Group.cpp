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
 //每次将这一段的最后一个插入到头之前,写了很久，开始用递归写，总有错误
class Solution {
public:

    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(k < 2 || head == NULL)return head;

        ListNode **cur = &head;
        int j = 1;
        while(1)
        {
        	ListNode** pTail = cur;
        	ListNode** pHead = cur;
        	ListNode* tp;
        	for(j = k; j >= 2; --j)
        	{
        		for(int i = 2; i <= j; ++i)
        		{
        			if((*pTail)->next == NULL)
        			{
        				return head;
        			}
        			pTail = &((*pTail)->next);
        		}

        		tp = *pTail;
        		*pTail = (*pTail)->next;
        		tp->next = (*pHead);
        		*pHead = tp;

        		pHead = &(tp->next);
        		pTail = pHead;
        	}
        	
        	if((*pTail)->next == NULL)break;
        	cur = &((*pTail)->next);
        }

        return head;
    }
};