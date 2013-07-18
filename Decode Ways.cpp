/*

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

//递归实现
class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s_length = s.length();
        if(s_length == 0)return 0;
        if(s[0] == '0')return 0;
        if(s_length == 1)return 1;

        if(s[0] > '2')
        	return numDecodings(s.substr(1, s_length - 1));
        else if(s[0] == '2')
        	if(s[1] <= '6')
        		return numDecodings(s.substr(1, s_length - 1)) + numDecodings(s.substr(2, s_length - 2));
        	else return numDecodings(s.substr(1, s_length - 1));
        else if(s[0] == '1')       	
        	return numDecodings(s.substr(1, s_length - 1)) + numDecodings(s.substr(2, s_length - 2));
    }
};