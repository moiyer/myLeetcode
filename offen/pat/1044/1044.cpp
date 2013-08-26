#include <iostream>
#include <climits>
using namespace std;

#include <iostream>
#include <climits>
using namespace std;

int solution(int data[], int n, int s)
{
	int l = 0, r = 0;
	int sum = data[0];
	int min_sum = INT_MAX;
	int num = 0;
	while(r < n && l <= r+1)
	{
		if(sum < s){
			r++;
			if(r < n)sum += data[r];
		}
		else if(sum > s){
			if(sum < min_sum)min_sum = sum;
			sum -= data[l];
			l++;
		}
		else {
			num++;
			printf("%d-%d\n", l+1, r+1);
			r++;
			if(r < n)sum += data[r];
			//continue;
		}
	}

	if(num == 0)return min_sum;
	else return -1;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int *data = new int[N];
	for(int i = 0; i < N; ++i)
		scanf("%d", data+i);

	int ret = solution(data, N, M);
	if(ret != -1)ret = solution(data, N, ret);

	delete [] data;
	system("pause");
	return 0;
}



#include <iostream>
#include <climits>
using namespace std;

int solution(int data[], int n, int s)
{
	int l = -1, r = 0;
	int sum = data[0];
	int min_sum = INT_MAX;
	int num = 0;
	while(r < n && l <= r)
	{
		if(sum < s){
			r++;
			if(r < n)sum += data[r];
		}
		else if(sum > s){
			if(sum < min_sum)min_sum = sum;
			if(l < r)sum -= data[l + 1];
			l++;
		}
		else {
			if(l < r){
				num++;
				cout << l + 2 << "-" << r + 1 << endl;
			}
			r++;
			if(r < n)sum += data[r];
		}
	}

	if(num == 0)return min_sum;
	else return -1;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int *data = new int[N]();
	for(int i = 0; i < N; ++i)
		cin >> data[i];

	int ret = solution(data, N, M);
	if(ret != -1)ret = solution(data, N, ret);

	delete [] data;
	system("pause");
	return 0;
}


#include <iostream>
#include <climits>
using namespace std;

int solution(int data[], int n, int s)
{
	int l = 0, r = 1;
	int sum = data[1];
	int min_sum = INT_MAX;
	int num = 0;
	while(r <= n && l <= r)
	{
		if(sum < s){
			r++;
			if(r <= n)sum += data[r];
		}
		else if(sum > s){
			if(sum < min_sum)min_sum = sum;
			if(l < r)sum -= data[l + 1];
			l++;
		}
		else {
			if(l < r){
				num++;
				cout << l + 1 << "-" << r << endl;
			}
			r++;
			if(r <= n)sum += data[r];
			//continue;
		}
	}

	if(num == 0)return min_sum;
	else return -1;
}

int main()
{
	int N, M;
	cin >> N >> M;
	int *data = new int[N + 1]();
	for(int i = 1; i <= N; ++i)
		cin >> data[i];

	int ret = solution(data, N + 1, M);
	if(ret != -1)ret = solution(data, N + 1, ret);

	delete [] data;
	system("pause");
	return 0;
}