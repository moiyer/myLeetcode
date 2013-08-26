#include <iostream>

using namespace std;

int data[8][8];
int dp[8][8];

int main()
{
	while(1){
	for(int i = 0; i < 8; ++i)
		for(int j = 0; j < 8; ++j)
			if(cin >> data[i][j]);
			else return;

	dp[0][0] = data[0][0];
	for(int i = 1; i <8; ++i)
		dp[0][i] = dp[0][i - 1] + data[0][i]; 
	
	for(int i = 1; i <8; ++i)
		dp[i][0] = dp[i - 1][0] + data[i][0];
	
	for(int i = 1; i < 8; ++i)
		for(int j = 1; j < 8; ++j)
		{
			int max = dp[i][ j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j];
			dp[i][j] = max + data[i][j];
		}

	cout << dp[7][7] << endl;
	}
	//system("pause");
	return 0;
}