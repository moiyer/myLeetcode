/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/
//2013/7/4 13:37:16
//大水题，没有自己写
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
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
 //(0)get list length
//(1)change the list to a loop list 
//(2)get real ratoate steps: k = k%length
//(3)head point move(<-) k steps  : i.e.  move(->) length-1-k steps

    ListNode *oList = head;
    if( k<=0 || !head || !(head->next) )
    {
        return oList;
    }

    int lLength = 0;
    ListNode* p = head;
    for( ; p->next!=NULL; p=p->next )
        lLength++;
    lLength++;

    k = k%lLength;
    if( k == 0 )
        return head;

    p->next = head;

    p = head;
    for(int i=0; i< lLength-1-k; i++)
        p=p->next;

    oList = p->next;
    p->next = NULL;  
    return oList;
    }
};