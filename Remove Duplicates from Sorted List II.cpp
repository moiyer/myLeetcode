/*

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

*/
//2013/7/15 14:43:15
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //水题,但是提交了几次
class Solution {
public:

    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL)return head;

        ListNode ** last = &head;
        ListNode **tp;

        int cur = head->val + 1;
        while((*last) != NULL && (*last)->next != NULL)
        {
        	if((*last)->val != ((*last)->next)->val)
        		last = &((*last)->next);
        	else{
        		cur = (*last)->val;
        		tp = last;
        		while((*last) != NULL && (*last)->val == cur)
        			last = &((*last)->next);
        		*tp = *last;
        		last = tp;
        	}
        }

        return head;
    }
};