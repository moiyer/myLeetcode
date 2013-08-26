#include <iostream>
#include <time.h>

using namespace std;

long long InversePares(int data[], int tp[], int l, int r)
{
	if(l == r)
	{
		tp[l] = data[l];
		return 0;
	}

	int m = l + ((r - l) / 2);
	long long lPares = InversePares(data, tp, l, m);
	long long rPares = InversePares(data, tp, m + 1, r);

	int i = m, j = r;
	long long mPares = 0;
	int cur = r;
	while(i >= l && j >= m + 1)
	{
		if(tp[i] <= tp[j])
		{
			data[cur--] = tp[j--];
		}else if(tp[i] > tp[j])
		{
			mPares += (j - m);
			data[cur--] = tp[i--];
		}
	}

	while(i >= l)data[cur--] = tp[i--];
	while(j >= m + 1)data[cur--] = tp[j--];

	for(cur = l; cur <= r; ++cur)
		tp[cur] = data[cur];

	return lPares + rPares + mPares;
}

long long get(int data[], int n)
{
	long long ret = 0;
	for(int i = 0; i < n; ++i){
		for(int k = i + 1; k < n; ++k)
			if(data[i] > data[k])ret += 1;
	}
	return ret;
}

void  test(int a = 10000)
{
	srand((unsigned)time(NULL)); 
	int err = 0;
	while(a-- >= 0)
	{
		int size = rand() % 100000 + 1;
		int *data = new int[size];
		int *tp = new int[size];
		for(int i = 0; i < size; ++i)
			data[i] = rand();
		int n = get(data, size);
		int m = InversePares(data, tp, 0, size - 1);

		if( m != n)
		{
			err++;
			cout << "error:" << m << " " << n << endl;
			for(int i = 0; i < size; ++i)
				cout << data[i] << " ";
			cout << endl;
		}else cout << "ok" << endl;
		delete[] data;
		delete[] tp;
	}
	cout << "err:" << err << endl;
}

int main()
{/*
	int n;
	cin >> n;
	int *data = new int[n];
	int *tp = new int[n];
	for(int i = 0; i < n; ++i)
		cin >> data[i];

	cout << InversePares(data, tp, 0, n - 1) << endl;
	delete[] data;
	delete[] tp;*/
	test();
	system("pause");
	return 0;
}

