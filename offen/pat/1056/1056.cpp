#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
	int id;
	int weight;
	int order;
	int rank;
}player;

bool compare(player& a, player& b)
{
	return a.order < b.order;
}

int main()
{
	int np, ng;
	cin >> np >> ng;
	player *data = new player[np];

	for(int i = 0; i < np; ++i)
	{
		cin >> data[i].weight;
		data[i].id = i;
	}

	for(int i = 0; i < np; ++i)
	{
		cin >> data[i].order;
	}
	sort(data, data + np, compare);

	for(int i = 0; i < np; ++i)
		cout << data[i].weight << "  "<< data[i].rank <<  endl;


	int j = np - 1;
	int round  = 0;
	int win = 0;
	while(j > 0)
	{
		win = 0;
		for(int i = 0; i <= j; i += ng)
		{
			int max = -1;
			int max_index = -1;
			int k;
			for(k = 0; k < ng && i + k <= j; ++k)
			{
				if(data[i + k].weight > max){
					max_index = i +k;
					max = data[i + k].weight;
				}
			}
			swap(data[win++], data[max_index]);
		}

		for(int s = win; s <= j; s++)
			data[s].rank = round;
		j = win - 1;
		round++;


		
		for(int ll = 0; ll < np; ++ll)
		cout << data[ll].weight << "  "<< data[ll].rank <<  endl;

	}

		for(int ll = 0; ll < np; ++ll)
		cout << data[ll].weight << "  "<< data[ll].id <<  " " << data[ll].rank << endl;

	data[0].rank = round;

	system("pause");
	return 0;
}
