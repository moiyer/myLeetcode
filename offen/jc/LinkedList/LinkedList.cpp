// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct _LLNode
{
	int val;
	struct _LLNode *next;
	_LLNode(int data)
	{
		val = data;
		next = NULL;
	}
}LLNode;

LLNode* generateLL(int data[], int n)
{
	if(n <= 0)return NULL;
	LLNode *head = new LLNode(data[0]);
	LLNode *tail = head;
	LLNode *tp = NULL;
	for(int i = 1; i < n; ++i)
	{
		tp = new LLNode(data[i]);
		tail->next = tp;
		tail = tp;
	}
	return head;
}

void printLL(LLNode* head)
{
	LLNode* cur = head;
	while(cur != NULL)
	{
		cout << cur->val;
		cur = cur->next;
		if(cur != NULL)cout << " -> ";
	}
	cout << endl;
}

//单链表快排
void partition(LLNode** phead, LLNode* tail)
{
	cout << "recursive:  " << (*phead)->val << " " << tail->val << endl;
	if(*phead == tail)return;

	LLNode *small_head, *big_head, *small_tail, *big_tail, *tp;
	LLNode **cur = &((*phead)->next);
	LLNode *end = tail->next;

	small_head = NULL;
	big_tail = NULL;
	small_head = NULL;
	small_tail = NULL;

	while(*cur != end)
	{
		if((*cur)->val >= (*phead)->val)
		{
			big_tail = *cur;
			cur = &((*cur)->next);
		}
		else{
			tp = *cur;
			*cur = (*cur)->next;
			if(small_head == NULL)
			{
				small_head = small_tail = tp;
				tp->next = NULL;
			}else
			{
				small_tail->next = tp;
				small_tail = tp;
				tp->next = NULL;
			}
		}
	}
//	printLL(*phead);
//	printLL(small_head);
//	cout << big_tail->val;

	tp = *phead;
	if(small_tail != NULL)
	{
		small_tail->next = *phead;

		//注意这一段不能忘记，重新设置head和tail
		*phead = small_head;
	}else small_tail = *phead;

	if(big_tail != NULL)
		tail = big_tail;
	else tail = tp;

	printLL(*phead);

	partition(phead, small_tail);
	if(tail != tp)partition(&(tp->next), tail);
}

//单链表归并排序
LLNode* mergeSort(LLNode *phead, int n)
{
	if(n == 1)return phead;

	int m = (n >> 1);
	LLNode *cur = phead;
	int i = 0;
	for(i = 0; i < m; ++i)
		cur = cur->next;

	int r = n - i;
	LLNode* low_head = mergeSort(phead, i);
	LLNode* high_head = mergeSort(cur, r);
	
	LLNode* new_head = NULL, *low_cur = low_head, *high_cur = high_head;
	if(low_head->val < high_head->val)
	{
		new_head = low_head;
		--i;
		low_cur = low_head->next;
	}else {
		new_head = high_head;
		--r;
		high_cur = high_head->next;
	}
	LLNode* new_tail = new_head;
	while(i > 0 && r > 0)
	{
		if(low_cur->val < high_cur->val)
		{
			new_tail->next = low_cur;
			new_tail = low_cur;
			--i;
			low_cur = low_cur->next;
		}else{
			new_tail->next = high_cur;
			new_tail = high_cur;
			--r;
			high_cur = high_cur->next;
		}
	}

	while(i > 0)
	{
		new_tail->next = low_cur;
		new_tail = low_cur;
		--i;
		low_cur = low_cur->next;
	}
	while(r > 0)
	{
		new_tail->next = high_cur;
		new_tail = high_cur;
		--r;
		high_cur = high_cur->next;
	}
	
	new_tail->next = NULL;
	return new_head;
}


int _tmain(int argc, _TCHAR* argv[])
{
	int data1[] = {4};
	LLNode* head = generateLL(data1, 1);
	
	LLNode* cur = head;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}

	partition(&head, cur);
	printLL(head);

	cout << "merge-------" << endl;
	mergeSort(head, 1);
	printLL(head);

	system("pause");
	return 0;
}

