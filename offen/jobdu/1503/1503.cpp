#include <iostream>

using namespace std;

typedef struct _Node
{
	int val;
	struct _Node* lChild;
	struct _Node* rChild;
	_Node(int a):val(a), lChild(NULL), rChild(NULL){}
}Node;

void Convert(Node* head, Node** small, Node** big)
{
	if(head == NULL)
	{
		*small = NULL;
		*big = NULL;
		return;
	}

	Node* lsmall = head, *rsmall = head, *lbig = head, *rbig = head;
	if(head->lChild != NULL)
	{
		Convert(head->lChild, &lsmall, &lbig);
		lbig->rChild = head;
		head->lChild = lbig;		
	}
	if(head->rChild != NULL)
	{
		Convert(head->rChild, &rsmall, &rbig);
		head->rChild = rsmall;
		rsmall->lChild = head;		
	}
	*small = lsmall;
	*big = rbig;
}

int main()
{
	int data[] = {10, 6, 14, 4, 8, 12, 16};
	Node* tp[7];
	for(int i = 0; i < 7; ++i)
	{
		Node *cur = new Node(data[i]);
		tp[i] = cur;
	}

	for(int i = 0; i < 7; ++i)
	{
		int l = 2 * i + 1;
		if(l < 7)
			{
				tp[i]->lChild= tp[l];
				tp[i]->rChild = tp[l + 1];
		}
	}

	Node *a, *b;
	Convert(tp[0], &a, &b);
	cout << a->val << " " << b->val;
	system("pause");
	return 0;
}