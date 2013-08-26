#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	
	for(int j = 0; j < K; ++j){
		int *data = new int[N]();
		for(int i = 0; i < N; ++i)
			cin >> data[i];

		int cur = 1;
		int index = 0;
		stack<int> stk;
		bool ret = false;
		bool tp = true;
		while(1)
		{
			while(cur <= N && cur <= data[index])
			{
				if(stk.size() >= M)
				{
					ret = false;
					tp = false;
					break;
				}
				stk.push(cur++);
			}
			if(tp == false)break;

			while(!stk.empty() && stk.top() == data[index])
			{
				//cout << stk.top() << "--"; 
				stk.pop();
				index++;
			}
			if(cur > N && index >= N)
			{
				ret = true;
				break;
			}
			if(cur > data[index])
			{
				ret = false;
				break;
			}
		}
		if(ret)cout << "YES" << endl;
		else cout << "NO" << endl;
		delete [] data;
	}

	system("pause");
	return 0;
}