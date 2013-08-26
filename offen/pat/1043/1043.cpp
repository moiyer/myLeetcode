#include <iostream>

using namespace std;

typedef struct _Node
{
	int val;
	struct _Node* left;
	struct _Node* right;
	_Node(int a):val(a), left(NULL),right(NULL){}
}Node;

int errorNO = 0;
Node* generateBST(int data[], int l, int r)
{
	if(errorNO == 1)return NULL;
	if(l > r)return NULL;
	
	Node* cur = new Node(data[l]);
	if(l == r)return cur;
	
	int cut = l;
	for(int i = l + 1; i <= r; ++i)
		if(data[i] < data[l])cut = i;
		else break;
	for(int j = cut + 1; j <= r; ++j)
		if(data[j] < data[l])
		{
			delete cur;
			errorNO = 1;
			return NULL;
		}

	Node* ln = generateBST(data, l + 1, cut);
	Node* rn = generateBST(data, cut + 1, r);
	cur->left = ln;
	cur->right = rn;
	return cur;
}

Node* generateBSTM(int data[], int l, int r)
{
	if(errorNO == 1)return NULL;
	if(l > r)return NULL;
	
	Node* cur = new Node(data[l]);
	if(l == r)return cur;
	
	int cut = l;
	for(int i = l + 1; i <= r; ++i)
		if(data[i] >= data[l])cut = i;
		else break;
	for(int j = cut + 1; j <= r; ++j)
		if(data[j] >= data[l])
		{
			delete cur;
			errorNO = 1;
			return NULL;
		}

	Node* ln = generateBSTM(data, l + 1, cut);
	Node* rn = generateBSTM(data, cut + 1, r);
	cur->left = ln;
	cur->right = rn;
	return cur;
}

void postOrder(Node* head)
{
	if(head == NULL)return;
	postOrder(head->left);
	postOrder(head->right);
	cout << head->val << " ";
}

int main()
{
	int n;
	cin >> n;
	int *data = new int[n]();
	for(int i = 0; i < n; ++i)
		cin >> data[i];
	if(n < 2)
	{
		cout << "YES" << endl;
		cout << data[0] << endl;
	}
	Node * head;
	//if(data[0] > data[1])head = generateBST(data, 0, n - 1);
	//else head = generateBSTM(data, 0, n - 1);
	errorNO = 0;
	head = generateBST(data, 0, n - 1);
	if(errorNO == 1)
	{
			errorNO = 0;
			head = generateBSTM(data, 0, n - 1);
	}

	if(errorNO == 1)
	{
			cout << "NO" << endl;
			delete[] data;
			system("pause");
			return 0;
	}
	else {
		cout << "YES" << endl;
		postOrder(head->left);
		postOrder(head->right);
		cout << head->val <<endl;
	}
	delete [] data;
	system("pause");
	return 0;
}