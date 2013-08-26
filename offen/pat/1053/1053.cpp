#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct _Node
{
	int weight;
	vector<struct _Node*> child;
	_Node(int w): weight(w){}
}Node;

bool compare(Node* a, Node* b)
{
	return a->weight > b->weight;
}

int N, M, S;

Node* generateTree()
{
	cin >> N >> M >> S;
	Node** data = (Node**)malloc(sizeof(Node*) * N);
	int tp_weight, tp_node, tp_num, tp_child;

	for(int i = 0; i < N; ++i)
	{
		cin >> tp_weight;
		Node *tp = new Node(tp_weight);
		data[i] = tp;
	}

	for(int i = 0; i < M; ++i)
	{
		cin >> tp_node >> tp_num;
		for(int j = 0; j < tp_num; ++j)
		{
			cin >> tp_child;
			data[tp_node]->child.push_back(data[tp_child]);
		}
	}

	return data[0];
}

void dfs(Node* head, vector<int>& tp, int left)
{
	if(head->weight > left)return;
	else if(head->weight == left){
		if(head->child.empty()){
			vector<int>::iterator it = tp.begin();
			cout << *it;
			it++;
			for(; it != tp.end(); ++it)
				cout << " " << *it;
			cout << endl;
			return;
		}else return;
	}

	left -= head->weight;
	sort(head->child.begin(), head->child.end(), compare);
	vector<Node *>::iterator hit = head->child.begin();
	for(; hit != head->child.end(); ++hit)
	{
		tp.push_back((*hit)->weight);
		dfs(*hit, tp, left);
		tp.pop_back();
	}
}

int main()
{
	Node* head = generateTree();
	vector<int> tp;
	tp.push_back(head->weight);
	dfs(head, tp, S);
	system("pause");
}