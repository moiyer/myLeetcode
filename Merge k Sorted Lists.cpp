/*

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //2013/6/10 21:11:29
 //这是一道水题，注意vector里面的指针可能全为NULL
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = lists.size();
        if(size == 0)return NULL;

        ListNode** cursors = new ListNode*[size];
        int endList = 0;
        int min = INT_MAX;
        int indexMin;
        int i;

        ListNode* head, *tail;
        head  = new ListNode(0);
        tail = head;

        for(i = 0; i < size; ++i)
        {
        	cursors[i] = lists[i];
        	if(cursors[i] == NULL)endList++;//注意这个地方容易忘掉，避免cursors[i]开始就为空时endList没有记录
        }

        while(endList < size)
        {
        	min = INT_MAX;
        	for(i = 0; i < size; ++i)
        	{
        		if(cursors[i] == NULL)
        			continue;
        		if(min > cursors[i]->val)
        		{
        			min = cursors[i]->val;
        			indexMin = i;
        		}
        	}
        	ListNode* ln = new ListNode(min);
        	tail->next = ln;
        	tail = ln;
        	cursors[indexMin] = cursors[indexMin]->next;
        	if(cursors[indexMin] == NULL)endList++;
        }

        delete[] cursors;
        return head->next;

    }
};