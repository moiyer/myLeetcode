#include <iostream>

using namespace std;

typedef struct _ListNode
{
	int val;
	struct _ListNode *next;
	_ListNode(int a):val(a),next(NULL){}
}ListNode;

ListNode* reverse(ListNode* head)
{
	if(head == NULL)return NULL;
	if(head->next == NULL)return head;
	else
	{
		ListNode* ret = reverse(head->next);
		head->next->next = head;
		head->next = NULL;
		return ret;
	}
}

int data[1000];
int main()
{
	int n;
	while(cin >> n)
	{
		if(n <= 0)
		{
			cout << "NULL" << endl;
			break;
		}

		for(int i = 0; i < n; ++i)
			cin >> data[i];
		ListNode * head = new ListNode(data[0]);
		ListNode *cur = head;
		for(int i = 1; i < n; ++i)
		{
			ListNode* tp = new ListNode(data[i]);
			cur->next = tp;
			cur = tp;
		}

		head = reverse(head);
		cur = head;
		while(cur->next != NULL)
		{
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << cur->val << endl;
	}
	system("pause");
	return 0;
}