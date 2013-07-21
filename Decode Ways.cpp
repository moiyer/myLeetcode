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

//2013/7/19 21:42:07
//递归实现,大数据超时
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
                if(s_length > 2)
        		  return numDecodings(s.substr(1, s_length - 1)) + numDecodings(s.substr(2, s_length - 2));
                else return numDecodings(s.substr(1, s_length - 1)) + 1;
        	else return numDecodings(s.substr(1, s_length - 1));
        else if(s[0] == '1')
            if(s_length > 2)       	
        	   return numDecodings(s.substr(1, s_length - 1)) + numDecodings(s.substr(2, s_length - 2));
            else return numDecodings(s.substr(1, s_length - 1)) + 1;
    }
};

//2013/7/19 21:44:35
//动态规划
class Solution {
public:
    bool check(int num, string sub)
    {
        if(num == 1)
        {
            if(sub[0] != '0')return true;
            else return false;
        }
        if(num == 2)
        {
            if(sub[0] > '2' || sub[0] == '0')return false;
            if(sub[0] == '1')return true;
            if(sub[0] == '2' && sub[1] <= '6')return true;
            else return false;
        }
    }

    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s_length = s.length();
        if(s_length == 0)return 0;

        int *dp = new int[s_length + 1]();

        // if(s_length == 1)
        // {
        //     if(check(1, s))return 1;
        //     else return 0;
        // }

//         if(s_length == 2)
//         {
// ()           if(check(2, s))
//                 if(check(1, s) && check(1, s.substr(1, 1)))
//                     return 2;
//                 else return 1;
//             else if(check(1, s) && check(1, s.substr(1, 1)))
//                 return 1;
//             else return 0;
//         }

        dp[0] = 1;
        if(check(1, s))dp[1] = 1;
        else dp[1] = 0;
        for(int i = 1; i < s_length; ++i)
        {
            if(check(1, s.substr(i, 1)))
                dp[i + 1] += dp[i];

            if(check(2, s.substr(i - 1, 2)))
                dp[i + 1] += dp[i - 1];
        }

        int ret = dp[s_length];
        delete [] dp;
        return ret;
    }
};