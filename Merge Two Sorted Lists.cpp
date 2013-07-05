/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

*/
//2013/7/4 20:09:09
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //水题
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;

        ListNode* head, *p;
        if(l1->val < l2->val)
        {
        	head = l1;
        	l1 = l1->next;
        }else{
        	head = l2;
        	l2 = l2->next;
        }

        p = head;

        while(l1 != NULL && l2 != NULL)
        {
        	if(l1->val < l2->val)
        	{
        		p->next = l1;
        		p = l1;
        		l1 = l1->next;
        	}else{
        		p->next = l2;
        		p = l2;
        		l2 = l2->next;
        	}
        }

        if(l1 == NULL)p->next = l2;
        if(l2 == NULL)p->next = l1;

        return head;
    }
};