/*

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

*/

//2013/7/3 19:59:02
//水题，没有自己写
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int lastPos = strlen(s) - 1;
		while(lastPos >=0 && s[lastPos] == ' ')
			lastPos--;
		int res = 0;
		while (lastPos >=0 && s[lastPos--] != ' ')
			res++;
		return res;
	}
};