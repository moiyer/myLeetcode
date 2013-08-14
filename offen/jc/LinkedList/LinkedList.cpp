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

//单链表节点交换
//注意两个节点可能相邻
void swapLL(LLNode **a, LLNode **b)
{
	if((*a)->next == *b)
	{
		LLNode* tp = *a;
		*a = *b;
		tp->next = (*b)->next;
		(*a)->next = tp;
		return;
	}
	if((*b)->next == *a)swapLL(b, a);
	swap((*a)->next, (*b)->next);
	swap(*a, *b);
}

//双链表节点交换
//注意首尾和相邻
typedef struct _DLNode
{
	int val;
	struct _DLNode *left;
	struct _DLNode *right;
	_DLNode(int data)
	{
		val = data;
		left = NULL;
		right = NULL;
	}
}DLNode;

DLNode* generateDL(int data[], int n)
{
	if(n <= 0)return NULL;
	DLNode *head = new DLNode(data[0]);
	DLNode *tail = head;
	DLNode *tp = NULL;
	for(int i = 1; i < n; ++i)
	{
		tp = new DLNode(data[i]);
		tail->right = tp;
		tp->left = tail;
		tail = tp;
	}
	return head;
}

void printDL(DLNode* head)
{
	DLNode* cur = head;
	DLNode* cur_r = head->right;
	cout << cur->val;
	if(cur_r == NULL)return;

	cout << " == ";
	while(cur_r != NULL && cur_r->left == cur)
	{
		cout << cur_r->val;
		cur = cur->right;
		cur_r = cur_r->right;
		if(cur_r != NULL)cout << " == ";
	}
	cout << endl;
}

void swapDL(DLNode* a, DLNode* b)
{
	if(a == b)return;
	if(a->right == b)
	{
		DLNode *tp = b->right;
		if(a->left != NULL)
		{
			a->left->right = b;
		}
		a->right = b->right;
		b->right = a;

		if(tp != NULL)
		{
			tp->left = a;
		}
		b->left = a->left;
		a->left = b;

		return;
	}else if(b->right == a)swapDL(b, a);

	if(a->left != NULL && b->left != NULL)
		swap(a->left->right, b->left->right);
	else if(a->left == NULL)b->left->right = a;
	else if(b->left == NULL)a->left->right = b;
	
	swap(a->left, b->left);
	
	if(a->right != NULL && b->right != NULL)
		swap(a->right->left, b->right->left);
	else if(a->right == NULL)b->right->left = a;
	else if(b->right == NULL)a->right->left = b;
	
	swap(a->right, b->right);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int data1[] = {4, 5, 7};
	LLNode* head = generateLL(data1, 3);
	
	swapLL(&head, &(head->next));
	printLL(head);

	cout << "end" << endl;

	LLNode* cur = head;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}

	partition(&head, cur);
	printLL(head);

	cout << "merge-------" << endl;
	mergeSort(head, 3);
	printLL(head);

	cout << "doubled linked list swap" << endl;
	int data2[] = {1, 2, 3, 4};
	DLNode* dhead = generateDL(data2, 4);
	printDL(dhead);
	swapDL(dhead->right, dhead->right->right->right);
	printDL(dhead);//注意交换之后dhead不一定再指向链表头

	system("pause");
	return 0;
}

