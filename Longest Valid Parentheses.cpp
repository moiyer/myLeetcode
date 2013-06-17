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

//2013/6/17 14:47:01
//使用计数和模板实现
//Find from left to right by a forward iterator and right to left by a reverse iterator. 
//Using template to avoid duplicate code since a reverse iterator overloads the operator +.
class Solution {
public:
    int longestValidParentheses(string s) {
        return max( helper(s.begin(), s.end(), '('), helper(s.rbegin(), s.rend(), ')') );
    }

    template<class Iter>
    int helper(Iter beg, Iter end, char ch) {
        int ret = 0;
        int left = 0, right = 0;
        for ( ; beg != end; ++beg) {
            if (*beg == ch) {
                ++left;
            }
            else if (left > right) {
                ++right;
                if (left == right) {
                    ret = max(ret, left<<1);
                }
            }
            else {
                left = right = 0;
            }
        }
        return ret;
    }
};

//2013/6/17 14:56:01
//这种方法比较主流
//Use a stack to keep track of the positions of non-matching '('s. 
//Also need to keep track of the position of the last ')'.
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0, last = -1;
        stack<int> lefts;
        for (int i=0; i<s.length(); ++i) {
            if (s[i]=='(') {
                lefts.push(i);
            } else {
                if (lefts.empty()) {
                // no matching left
                    last = i;
                } else {
                // find a matching pair
                    lefts.pop();
                    if (lefts.empty()) {
                        maxLen = max(maxLen, i-last);
                    } else {
                        maxLen = max(maxLen, i-lefts.top());
                    }
                }
            }
        }
        return maxLen;
    }
};