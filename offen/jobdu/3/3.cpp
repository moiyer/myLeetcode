#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
		int *data = new int[N]();
		for(int i = 0; i < N; ++i)
			cin >> data[i];

		sort(data, data + N);
		int sum = 0;
		int index = 0;
		while (index < N)
		{
			if(sum + 1 < data[index])break;
			sum += data[index];
			index++;
		}
		cout << sum + 1 << endl;
		delete [] data;
	}
	system("pause");
	return 0;
}