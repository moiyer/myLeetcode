#include <iostream>
#include <algorithm>

using namespace std;

bool isOk(char data[], int cur, int i)
{
	bool ret = true;
	for(int j = cur; j < i; ++j)
		if(data[j] == data[i])ret = false;
	return ret;
}

void permutation(char data[], int n, int cur)
{
	if(cur == n - 1)
	{
		cout << data << endl;
		return;
	}

	for(int i = cur; i < n - 1; ++i)
	{
		if(isOk(data, cur, i) == false)continue;

		swap(data[i], data[cur]);
		permutation(data, n, cur + 1);
		swap(data[i], data[cur]);
	}
}

int main()
{
	char data[] = {'a', 'b', 'b', 'd', '\0'};
	sort(data, data + 4);
	permutation(data, 5, 0);
	system("pause");
	return 0;
}