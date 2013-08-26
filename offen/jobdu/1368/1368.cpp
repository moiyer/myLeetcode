#include <iostream>
#include <vector>

using namespace std;

typedef struct _Node
{
	int val;
	struct _Node* lChild;
	struct _Node* rChild;
}Node;

void FindPath(Node* head, vector<int> &path, int sum, int current_sum)
{
	if(head->lChild == NULL && head->rChild == NULL)
	{
		if(sum == current_sum)
		{
			int size = path.size();
			for(int i = 0; i < size; ++i)
				cout << path[i] << " ";
			cout << endl;
		}
		return;
	}

	current_sum += head->val;
	path.push_back(head->val);

	if(head->lChild != NULL)
		FindPath(head->lChild, path, sum, current_sum);
	if(head->rChild != NULL)
		FindPath(head->rChild, path, sum, current_sum);

	path.pop_back();
}

int main()
{
	system("pause");
	return 0;
}