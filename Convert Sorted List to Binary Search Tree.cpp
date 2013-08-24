/*

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

*/
//2013/8/24 16:46:43
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)return NULL;
        if(head->next == NULL)return new TreeNode(head->val);

        ListNode* fast = head, *slow = head;
        ListNode* pre = NULL;
        while(fast != NULL && fast->next != NULL)
        {
        	pre = slow;
        	fast = fast->next->next;
        	slow = slow->next;
        }

        if(pre != NULL)pre->next = NULL;
        TreeNode *cur = new TreeNode(slow->val);
        cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(slow->next);

        return cur;
    }
};