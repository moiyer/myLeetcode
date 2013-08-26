#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

typedef struct _people
{
	string name;
	int age;
	int worth;
}people;

bool compare(people const& l, people const& r)
	{
		if(l.worth == r.worth)
			if(l.age == r.age)
				return l.name < r.name;
			else return l.age < r.age;
		else return l.worth > r.worth;
	}

int main()
{
	int n, k;
	int i = 0;
	char nam[9] = {0};
	cin >> n >> k;
	people *data = new people[n];
	for(i = 0; i < n; ++i)
	{
		scanf("%s%d%d", nam, &data[i].age, &data[i].worth);
		data[i].name = nam;
	}
	sort(data, data + n, compare);
	int M, Amin, Amax;
	for(i = 1; i <= k; ++i)
	{
		scanf("%d%d%d", &M, &Amin, &Amax);
		printf("Case #%d:", i);
		int num = 0;
		for(int j = 0; j < n && num < M; ++j)
		{
			if(data[j].age <= Amax && data[j].age >= Amin)
			{
				num++;
				printf("%s %d %d\n", data[j].name.c_str(), data[j].age, data[j].worth);
			}
		}
		if(num == 0)printf("None\n");
	}
	delete [] data;
	//system("pause");
	return 0;
}