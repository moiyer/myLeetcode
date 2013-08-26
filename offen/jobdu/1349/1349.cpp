#include <iostream>

using namespace std;

int FindFirst(int data[], int n, int query)
{
	if(data == NULL || n <= 0)
		return -1;
	int l = 0, r = n - 1;
	int m;

	while(l < r)
	{
		m = l + ((r - l) >> 1);
		if(data[m] >= query)
			r = m;
		else l = m + 1;
	}

	if(data[r] == query)return r;
	else return -1;
}

int FindLast(int data[], int n, int query)
{
	if(data == NULL || n <= 0)
	{
		return -1;
	}

	int l = 0, r = n - 1;
	int m;

	while(l < r)
	{
		m = l + ((r - l) >> 1);
		if(data[m] > query)
			r = m - 1;
		else if(l != m)l = m;
		else {
			if(data[l + 1] == query)return l + 1;
			break;
		}
	}

	if(data[l] == query)return l;
	else return -1;
}

int main()
{
	int n;
	cin >> n;
	int *data = new int[n];
	for(int i = 0; i < n; ++i)
		cin >> data[i];

	int m;
	int query;
	cin >> m;
	for(int i = 0;i < m; ++i)
	{
		cin >> query;
		int left = FindFirst(data, n, query);
		if(left != -1)
			{
				int right = FindLast(data, n, query);
				cout << "left" << left << "    " << right - left + 1 << endl;
		}else cout << "0" << endl;
	}
	system("pause");
	return 0;
}

