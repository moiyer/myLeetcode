/*

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

*/
//2013/7/15 13:16:12
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
	void deleteDuplicatesRecursive(ListNode *head, ListNode *cur)
	{
		if(head == NULL)return;

		if(head->val == cur->val)
		{
			cur->next = head->next;
			// head = head->next;
		}else{
			cur = cur->next;
		}
		head = head->next;

		deleteDuplicatesRecursive(head, cur);
		return;
	}

    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)return NULL;

        deleteDuplicatesRecursive(head->next, head);
        return head;
    }
};