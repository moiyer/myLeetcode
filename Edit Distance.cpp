/*

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

*/
//2013/7/6 17:48:36
//二维动态规划,编程之美上的题目
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size1 = word1.size();
        int size2 = word2.size();
        if(size2 == 0)return size1;
        if(size1 == 0)return size2;

        int *dp = new int[(size1 + 1) * (size2 + 1)]();

        for(int i = 0; i <= size1; ++i)
        	dp[i * (size2 +1) + size2] = size1 - i;
        for(int i = 0; i <= size2; ++i)
        	dp[size1 * (size2 + 1) + i] = size2 - i;

        for(int i = size1 - 1; i >= 0; --i)
        	for(int j = size2 - 1; j >= 0; --j)
        		dp[i * (size2 + 1) + j] = min(min(dp[(i + 1) * (size2 + 1) + j] + 1, dp[i * (size2 + 1) + j + 1] + 1), word1[i] == word2[j] ? dp[(i + 1) * (size2 + 1) + j + 1] : dp[(i + 1) * (size2 + 1) + j + 1] + 1);

        int ret = dp[0];
        delete [] dp;
        return ret;
    }
};