/*

Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

*/
//2013/8/25 16:58:53
//二维动态规划
//设母串的长度为 j,子串的长度为 i，我们要求的就是长度为 i 的字串在长度为 j 的母串中出现的次数，设为 t[i][j]，若  
// 母串的最后一个字符与子串的最后一个字符不同，则长度为 i 的子串在长度为 j 的母串中出现的次数就是  
// 母串的前 j - 1 个字符中子串出现的次数，即 t[i][j] = t[i][j - 1]，若母串的最后一个字符与子  
// 串的最后一个字符相同，那么除了前 j - 1 个字符出现字串的次数外，还要加上子串的前 i - 1 个字符  
// 在母串的前 j - 1 个字符中出现的次数，即 t[i][j] = t[i][j - 1] + t[i - 1][j - 1]。
class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int s_size = S.length();
        int t_size = T.length();

        if(s_size == 0 || t_size == 0)return 0;

        int *dp = new int[s_size * t_size]();

        if(S[0] == T[0])dp[0] = 1;
        else dp[0] = 0;

        for(int j = 1; j < s_size; ++j)
        	if(S[j] == T[0])dp[j] = dp[j - 1] + 1;
        	else dp[j] = dp[j - 1];

        for(int i = 1; i < t_size; ++i)
        {
        	for(int j = 1; j < s_size; ++j)
        	{
        		if(S[j] != T[i])dp[i * s_size + j] = dp[i * s_size + j - 1];
        		else dp[i * s_size + j] = dp[i * s_size + j - 1] + dp[(i - 1) * s_size + j - 1];
        	}
        }

        int ret = dp[(t_size - 1) * s_size + s_size - 1];
        delete [] dp;

        return ret;
    }
};