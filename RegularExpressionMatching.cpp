/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
*/

//使用F5插入日期时间

//2013/6/7 16:23:28
//递归解决，每次递归判断下一个是否是‘*’,注意递归终止条件
//在"bbbba", ".*a*a"时Runtime Error
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if(s == NULL || p == NULL)return false;
        // if( *s == '\0' && ((*p == '\0') || (*(p + 1) == '*' && *(p + 2) == '\0')))return true;//此处终止条件容易漏掉
        if((*s == '\0') && (*p == '\0'))return true;
        if((*s == '\0') && (*(p + 1) == '*'))return isMatch(s, p + 2);
        if(*s == '\0')return false;
        if(*p == '\0')return false;
        //if((*s == '\0' && *p != '\0') || (*s != '\0' && *p == '\0'))return false;

        if(*(p + 1) != '*')
        {
            if(*p == '.' || *s == *p)
        		return isMatch(s + 1, p + 1);
        	else return false;
        }else
        {
        	while(s != '\0' && (*s == *p || *p == '.'))
        		if(isMatch(++s, p + 2))
        			return true;
        	return isMatch(s, p + 2);
        }
    }
};