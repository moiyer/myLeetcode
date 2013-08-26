#include <iostream>
#include <string>

using namespace std;

int main()
{
			string input;
					int times[26];
	while(cin >> input){

		for(int i = 0; i < 26; ++i)
			times[i] = -1;

		int size = input.length();
		int max_length = 0;
		int mm = -1;
		//times[input[0] - 'a'] = 0;
		int l = 0, r = 0;

		while(r < size)
		{
			if(times[input[r] - 'a'] == -1)
			{
				max_length++;
				mm = (mm > max_length ? mm : max_length);
				times[input[r] - 'a'] = r;
				r++;
			}else{
				max_length = r - times[input[r] - 'a'];
				mm = (mm > max_length ? mm : max_length);
				for(int k = l; k < times[input[r] - 'a']; ++k)
					times[input[k] - 'a'] = -1;
				l = times[input[r] - 'a'] + 1;
				times[input[r] - 'a'] = r;
				r++;
			}
		}

		cout << mm << endl;
	}
	system("pause");
	return 0;
}