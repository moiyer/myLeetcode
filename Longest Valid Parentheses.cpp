/*

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

*/

//2013/6/14 15:27:01
//从前往后扫描，使用变量记录'('和')'的数量，left < right时将变量清零，这种思路错误，"()(()"
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxLength = 0;
        int left = 0, right = 0;
        int cur = 0;
        int length = s.length();

        for(; cur < length; ++cur)
        {
        	if(s[cur] == '(')
        		++left;
        	else{
        		++right;
        		if(left < right)
        		{
        			maxLength = max(maxLength, left);
        			left = 0;
        			right = 0;
        		}
        	}
        }

        int m = min(left, right);
        maxLength = max(maxLength, m);

        return maxLength << 1;
    }
};

//2013/6/14 17:13:47
//使用stack记录'('

class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxLength = 0;
        stack<int> left;

        int size = s.length();

        for(int i = 0; i < size; ++i)
        {
        	if(s[i] == '(')left.push(i);
        }

        return maxLength << 1;
    }
};