/*

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

*/
//2013/6/18 13:44:08
//比较简单，自己没写
class Solution {
public:
	string unguarded_convert(const string &say)
	{
		stringstream ss;
		int count = 0;
		char last = say[0];

		for (size_t i = 0; i <= say.size(); ++i)
		{
			if (say[i] == last)
			{
				++count;
			}
			else
			{
				ss << count << last;
				count = 1;
				last = say[i];
			}
		}

		return ss.str();
	}

	string countAndSay(int n) 
	{
		if (n <= 0) return string();

		string say = "1";

		for (int i = 1; i < n; ++i)
		{
			say = unguarded_convert(say);
		}

		return say;
	}
};