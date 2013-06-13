/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //2013/6/10 21:56:16
 //这是一道水题，使用指向指针的指针比较方便
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)return NULL;

        ListNode** first, **second, **cur, *tmp;

        cur = &head;
        while(*cur != NULL)
        {
        	first = cur;
        	if((*cur)->next == NULL)break;
        	second = &((*cur)->next);

        	tmp = *second;
        	(*first)->next = (*second)->next;
        	tmp->next = *first;
        	*first = tmp;

        	cur = second;
        }

        return head;
    }
};