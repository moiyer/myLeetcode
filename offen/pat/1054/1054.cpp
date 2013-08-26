#include <stdio.h>


int main()
{
	int m, n;
	int dominant = -1;
	int cur, i, j;
	int times = 0;
	scanf("%d%d", &m, &n);
	for(i = 0; i < n * m ;++i)
		{
			scanf("%d", &cur);
			if(times == 0)
			{
				dominant = cur;
				times = 1;
			}else if(cur == dominant)
			{
				times++;
			}else times--;
		}
	printf("%d",dominant);
	return 0;
}