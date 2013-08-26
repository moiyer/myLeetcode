// tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

typedef struct _Node
{
	int val;
	struct _Node* lChild;
	struct _Node* rChild;
	_Node(int a):val(a),lChild(NULL),rChild(NULL){}
}Node;

Node* generateTree(int data[], int n)
{
	Node* head = new Node(data[0]);
	Node** tp = (Node**)malloc( sizeof(Node*) * n);
	int i = 1;
	tp[0] = head;
	while(i < n)
	{
		if(data[i] < 0){
			++i;
			continue;
		}
		Node* tt = new Node(data[i]);
		tp[i] = tt;
		if(i % 2)tp[(i - 1) / 2]->lChild = tt;
		else tp[(i - 1) / 2]->rChild = tt;
		++i;
	}
	free(tp);
	return head;
}

//�����ӡ
void printTree(Node* head)
{
	if(head == NULL)return;
	Node* level_cut = new Node(-1);
	queue<Node*> tp;
	tp.push(head);
	tp.push(level_cut);
	while(!tp.empty())
	{
		Node* cur = tp.front();
		tp.pop();
		if(cur->val >= 0)cout << cur->val;
		else{
			if(tp.empty())break;
			tp.push(level_cut);
			cout << endl;
			continue;
		}
		if(cur->lChild != NULL)tp.push(cur->lChild);
		if(cur->rChild != NULL)tp.push(cur->rChild);
		if(!tp.empty())cout << "	";
	}
	cout << endl;
}

//����������ݹ�
void preOrder(Node* head)
{
	if(head == NULL)return;
	cout << head->val << " ";
	if(head->lChild != NULL)preOrder(head->lChild);
	if(head->rChild != NULL)preOrder(head->rChild);
}

//���������ѭ��ʵ��
void preOrderTravel(Node* head)
{
	stack<Node*> tp;
	Node* cur = head;

	while(cur != NULL)
	{
		while(cur != NULL)
		{
			cout << cur->val << " ";
			tp.push(cur);
			cur = cur->lChild;
		}

		cur = tp.top();
		tp.pop();
		while(cur->rChild == NULL && !tp.empty())
		{
			cur = tp.top();
			tp.pop();
		}
		cur = cur->rChild;
	}
}

//���������ѭ��ʵ��,��������
void inOrderTravel(Node* head)
{
	stack<Node*> tp;
	Node* cur = head;

	while(cur != NULL)
	{
		while(cur != NULL)
		{
			tp.push(cur);
			cur = cur->lChild;
		}

		cur = tp.top();
		cout << cur->val << " ";
		tp.pop();
		while(cur->rChild == NULL && !tp.empty())
		{
			cur = tp.top();
			cout << cur->val << " ";
			tp.pop();
		}
		cur = cur->rChild;
	}
}

//���������ѭ��ʵ��,�����Ƚ��鷳
/*
Ҫ��֤����������Ӻ��Һ��ӷ���֮����ܷ��ʣ���˶�����һ���P���Ƚ�����ջ�����P���������Ӻ��Һ��ӣ������ֱ�ӷ�������
����P�������ӻ����Һ��ӣ����������Ӻ��Һ��Ӷ��ѱ����ʹ��ˣ���ͬ������ֱ�ӷ��ʸý�㡣
�������������������P���Һ��Ӻ�����������ջ�������ͱ�֤��ÿ��ȡջ��Ԫ�ص�ʱ���������Һ���ǰ�汻���ʣ����Ӻ��Һ��Ӷ��ڸ����ǰ�汻���ʡ�
*/
void backOrderTravel(Node* head)
{
	if(head == NULL)return;

	stack<Node*> data;
	Node* cur, *pre = NULL;
	data.push(head);

	while(!data.empty())
	{
		cur = data.top();
		if((cur->lChild == NULL && cur->rChild == NULL) || ((pre != NULL) && (pre == cur->lChild || pre == cur->rChild)))
		{
			cout << cur->val << " ";
			data.pop();
			pre = cur;
		}else
		{
			if(cur->rChild != NULL)
				data.push(cur->rChild);
			if(cur->lChild != NULL)
				data.push(cur->lChild);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int data[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	Node* head = generateTree(data, 16);
	printTree(head);
	cout << endl;
	cout << "preorder" << endl;
	preOrder(head);
	cout << endl;
	inOrderTravel(head);
	cout << endl;
	backOrderTravel(head);

	system("pause");
	return 0;
}

