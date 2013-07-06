/*

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/
//2013/7/6 16:47:16
//动态规划
class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    	if(n <= 1)return 1;

        int sum = 0;
        int *dp = new int[n + 1]();

        dp[n] = 1;
        dp[n - 1] = 2;
        for(int j = n - 2; j >= 1; --j)
        {
        	dp[j] = dp[j + 1] + dp[j + 2];
        }

        int ret = dp[1];
        delete [] dp;
        return ret;
    }
};