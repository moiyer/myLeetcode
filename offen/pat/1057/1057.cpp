#include <iostream>
#include <stack>
#include <string>
#include <set>

using namespace std;

int main()
{
	int n;
	cin >> n;
	stack<int> data;
	multiset<int> small, big;
	string order;
	int cur;
	for(int i = 0; i < n; ++i)
	{
		cin >> order;
		if(order == "Pop")
		{
			if(data.empty())
			{
				cout << "Invalid" << endl;
				continue;
			}
			data.pop();
			status.pop();
		}else if(order == "PeekMedian")
		{
			if(status.empty())
			{
				cout << "Invalid" << endl;
				continue;
			}
			else cout << status.top() << endl;
		}else if(order == "Push")
		{
			cin >> cur;
			if(data.empty())
			{
				data.push(cur);
				status.push(cur);
			}else{
				int size = data.size();
				if(cur < status.top())
					if(size)
			}
		}
	}
	system("pause");
	return 0;
}
