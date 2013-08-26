#include <iostream>

using namespace std;

const int SIZE = 1000;
int pre[SIZE];
int inner[SIZE];

typedef struct _Node
{
	int val;
	struct _Node *lChild;
	struct _Node *rChild;
	_Node(int a):val(a),lChild(NULL),rChild(NULL){}
}Node;

int errorNO = 0;
Node* constructTree(int pre_l, int pre_r, int inner_l, int inner_r)
{
	Node *cur = new Node(pre[pre_l]);

	if(pre_l == pre_r)
		if(inner_l == inner_r && pre[pre_l] == inner[inner_l])
			return cur;
		else{
			errorNO = 1;
			return NULL;
		}
	
	int i = inner_l;
	for(; i <= inner_r; ++i)
		if(inner[i] == pre[pre_l])break;
	if(i > inner_r)
	{
		errorNO = 1;
		return NULL;
	}
	int length = i - inner_l;
	if(length > 0)cur->lChild = constructTree(pre_l + 1, pre_l + length, inner_l, i - 1);
	if(i + 1 <= inner_r)cur->rChild = constructTree(pre_l + length + 1, pre_r, i + 1, inner_r);
	return cur;
}

void postTravel(Node * head)
{
	if(head == NULL)return;

	postTravel(head->lChild);
	postTravel(head->rChild);
	cout << head->val << " ";
}

int main()
{
	int n;
	while(cin >> n)
	{
		errorNO = 0;
		for(int i = 0; i < n; ++i)
			cin >> pre[i];
		for(int i = 0; i < n; ++i)
			cin >> inner[i];
		
		Node* head = constructTree(0, n - 1, 0, n - 1);

		if(errorNO == 1)cout << "No";
		else postTravel(head);
		cout << endl;
	}
	system("pause");
}