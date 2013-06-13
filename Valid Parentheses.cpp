/*

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

*/

//2013/6/9 21:44:43
//这是一道水题，熟悉一下stack的用法push(), pop(), top(), empty()

class Solution {
public:
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> left;
        char tp;

        int size = s.length();
        for(int i = 0; i < size; ++i)
        {
        	if(s[i] == '(' || s[i] == '[')
        		left.push(s[i]);
        	else if(s[i] == ')')
        	{
        		if(!left.empty() && left.top() == '(')left.pop();//注意此处要判断栈是否为空，先要想好测试用例
        			else return false;
        	}else if(s[i] == ']')
        	{
        		if(!left.empty() && left.top() == '[')left.pop();
        			else return false;
        	}
        }

        if(left.empty())return true;
        else return false;
    }
};