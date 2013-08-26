#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>

using namespace std;

void printAll(int n)
{
	string data(n + 1, '0');

	data[n] = '1';
	while(data[0] != '1')
	{
		//cout << data.substr(1) << endl;
		int j = 0;
		for(; j < n; ++j)
			if(data[j] != '0')break;

		cout << data.substr(j) << endl;
		
		for(int i = n; i >= 0; --i)
		{
			if(data[i] == '9')data[i] = '0';
			else{
				data[i]++;
				break;
			}
		}
	}
}

void printAllR(int n, char data[], int cur)
{
	if(cur == n)
	{
		int j = 0;
		for(; j < n; ++j)
			if(data[j] != '0')break;
		for(int i = j; i < n; ++i)
			printf("%c", data[i]);
		if(j < n)printf("\n");
		return;
	}

	for(int i = 0; i < 10; ++i)
	{
		data[cur] = '0' + i;
		printAllR(n, data, cur + 1);
	}
}

int main()
{
	int n;
	while(cin >> n)
	{
		//printAll(n);
		char *data = new char[n];
		printAllR(n, data, 0);
		delete [] data;
	}
	system("pause");
	return 0;
}