#include <iostream>
#include <stack>

using namespace std;


bool check(int push_seq[], int pop_seq[], int n)
{
	stack<int> s;
	int push_index = 0, pop_index = 0;

	while(pop_index < n)
	{
		if(!s.empty())
		{
			if(s.top() == pop_seq[pop_index])
			{
				s.pop();
				pop_index++;
				continue;
			}
		}
		while(push_index < n && push_seq[push_index] != pop_seq[pop_index])
			s.push(push_seq[push_index++]);
		if(push_index == n)return false;
		s.push(push_seq[push_index++]);
	}

	if(pop_index == n)return true;
}

int main()
{
	int n;
	while(cin >> n)
	{
		int *push_seq = new int[n]();
		int *pop_seq = new int[n]();
		for(int i = 0; i < n; ++i)
			cin >> push_seq[i];
		for(int i = 0; i < n; ++i)
			cin >> pop_seq[i];

		if(check(push_seq, pop_seq, n))
			cout << "Yes" << endl;
		else cout << "No" << endl;
		
		delete[] push_seq;
		delete[] pop_seq;
	}
	system("pause");
	return 0;
}