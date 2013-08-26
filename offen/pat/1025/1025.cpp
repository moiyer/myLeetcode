#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _testee
{
	char registration[13];
	int final_rank;
	int location;
	int local_rank;
	int score;
	bool operator<(Testee & b)
	{
		return score > b.score;
	}
}Testee;

int main()
{
	int N, K;
	cin >> N;
	Testee **all = (Testee **)malloc(sizeof(Testee*) * N);
	Testee *stu = (Testee *)malloc(sizeof(Testee) * 30000);
	//int *local_size = (int *)malloc(sizeof(int) * N);

	int number = 0;
	for(int i = 0; i < N; ++i)
	{
		cin >> K;
		//local_size[i] = K;
		Testee *local = (Testee*)malloc(sizeof(Testee) * K);
		for(int j = 0; j < K; ++j)
		{
			cin >> local[j].registration >> local[j].score;
			local[j].location = i;
			stu[number++] = local[j];
		}
		sort(local, local + K);
		all[i] = local;
		int last_score = 0;
		int last_rank = 0;
		for(int j = 0; j < K; ++j)
		{
			if(local[j].score < last_score)
			{
				last_rank++;
				local[j].local_rank = last_rank;
				last_score = local[j].score;
			}else{
				local[j].local_rank = last_rank;
			}
		}
	}

	while()
	system("pause");
}