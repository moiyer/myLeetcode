/*

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

*/
//2013/7/16 14:19:29
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //水题，没自己写
class Solution {
public:
ListNode *partition(ListNode *head, int x) {
if(head == NULL || head->next == NULL)
    return head;

// add a head node
ListNode *newHead = new ListNode(0);
newHead->next = head;

ListNode *insertPrev = newHead; //insert position
ListNode *passPre; 
while (head != NULL)
{
    if (newHead->next == head) //pass the first node
    {
        if (head->val < x)
            insertPrev =  passPre = head;
        else
            passPre = head;

        head = head->next;
    }
    else if (head->val >= x) //pass the node value > x
    {
        head = head->next;
        passPre = passPre->next;
    }
    else  //change the node
    {
        if (insertPrev == passPre)
        {
            insertPrev = passPre = head;
            head = head->next;
        }
        else
        {
            passPre->next = head->next;
            head->next = insertPrev->next;
            insertPrev->next = head;
            insertPrev = head;
            head = passPre->next;
        }

    }
}
return newHead->next;
}
};