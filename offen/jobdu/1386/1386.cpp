#include <stdio.h>


int main()
{
	int n;
	while(scanf("%d", &n))
	{
		int *data = new int[n]();
		for(int i = 0; i < n; ++i)
			scanf("%d", &data[i]);

		int l = 0, r = n - 1;
		int ret = l;
/*		while(l <= r)
		{
			if(data[l] <= data[r])
			{
				ret = l;
				break;
			}
			int m = l + ((r - l) >> 1);
			if(m == l)
			{
				ret = data[l] < data[r] ? l : r;
				break;
			}
			if(data[m] > data[l])l = m + 1;
			else if(data[m] < data[r])r = m;
			else l = m + 1;

		}*/
		while(l <= r)
		{
			if(data[l] < data[r] || l == r)
			{
				ret = l;
				break;
			}
			int m = l + ((r - l) >> 1);
			if(m == l)
			{
				ret = r;
				break;
			}

			if(data[m] == data[l] && data[m] == data[r])
			{
				int min_num = data[l];
			for(int i = l; i <= r; ++i)
				if(min_num > data[i])min_num = data[i];
			return min_num;
			}

			/*if(data[m] > data[l])l = m + 1;
			else if(data[m] < data[r])r = m;
			*/
			if(data[m] >= data[l])l = m;
			else if(data[m] <= data[r])r = m;
		}
		printf("%d\n", data[ret]);
	}
	return 0;
}

int solve(int num[], int n)
{
	int l = 0, r = n - 1;
	int min = l;
	while(num[l] >= num[r])
	{
		if(r - l == 1)
		{
			min = r;
			break;
		}

		int m = l + ((r - l) >> 1);
		if(num[m] == num[l] && num[m] == num[r])
		{
			int min_num = num[l];
			for(int i = l; i <= r; ++i)
				if(min_num > num[i])min_num = num[i];
			return min_num;
		}

		if(num[m] >= num[l])l = m;
		else if(num[m] <= num[r])r = m;
	}
	return num[min];
}