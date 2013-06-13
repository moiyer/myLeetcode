/*

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//2013/6/9 21:00:32
//这是一道水题，注意38行就行
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)return head;

        ListNode* pre = head;
        ListNode* succeed = head;
        for(int i = 0; i < n; ++i)
        	pre = pre->next;
        if(pre == NULL)   //这个地方要注意，可能删除的是头节点
        {
        	head = head->next;
        	return head;
        }
        while(pre->next != NULL)
        {
        	succeed = succeed->next;
        	pre = pre->next;
        }
        succeed->next = succeed->next->next;
        return head;
    }
};