#include <iostream>

using namespace std;

int data[54];
int input[54];
int output[54];

int main()
{
	int K;
	cin >> K;
	for(int i = 0; i < 54; ++i)
		cin >> input[i];

	for(int i = 0; i < 54; ++i)
		data[i] = i + 1;

	for(int i = 0; i < K; ++i)
	{
		for(int j = 0; j < 54; ++j)
			output[input[j] - 1] = data[j];
		//memcpy(input, output, 54 * sizeof(int));
		for(int j = 0; j < 54; ++j)
			data[j] = output[j];
	}

	int color = 0;
	int num = 0;
	for(int i = 0; i < 53; ++i)
	{
		color = output[i] / 13;
		num = output[i] % 13;
		if(num == 0)
		{
			num = 13;
			color--;
		}
		switch(color)
		{
		case 0:
			cout << "S";
			break;
		case 1:
			cout << "H";
			break;
		case 2:
			cout << "C";
			break;
		case 3:
			cout << "D";
			break;
		case 4:
			cout << "J";
			break;
		}
		
		cout << num << " ";
	}
	color = output[53] / 13;
		num = output[53] % 13;
				if(num == 0)
		{
			num = 13;
			color--;
		}
		switch(color)
		{
		case 0:
			cout << "S";
			break;
		case 1:
			cout << "H";
			break;
		case 2:
			cout << "C";
			break;
		case 3:
			cout << "D";
			break;
		case 4:
			cout << "J";
			break;
		}
		
		cout << num;
		system("pause");
}