#include <iostream>
#include <string>

using namespace std;

bool info[256];

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);

	for(int i = 0; i < 256; ++i)
		info[i] = false;
	string::iterator it2 = s2.begin();
	for(; it2 != s2.end(); ++it2)
		info[*it2] = true;
	string::iterator it1 = s1.begin();
	for(; it1 != s1.end(); ++it1)
	{
		if(info[*it1] == false)cout << *it1;
	}
	system("pause");
	return 0;
}