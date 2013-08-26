#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct
{
	string addr;
	int data;
	string next;
}Node;

bool compare(const Node& a, const Node& b)
{
	return a.data < b.data;
}

int main()
{
	int N;
	string head;
	cin >> N >> head;
	Node *nodeData = new Node[N];
	for(int i = 0; i < N; ++i)
	{
		cin >> nodeData[i].addr >> nodeData[i].data >> nodeData[i].next;
	}
	sort(nodeData, nodeData + N, compare);

	string pre = "-1";
	for(int i = N - 1; i >= 0; --i)
	{
		nodeData[i].next = pre;
		pre = nodeData[i].addr;
	}
	cout << N << " " << nodeData[0].addr << endl;
	for(int i = 0; i < N; ++i)
		cout << nodeData[i].addr << " " << nodeData[i].data << " " << nodeData[i].next << endl;
	system("pause");
}