/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

*/
//2013/7/4 14:26:09
//最简单的递归实现，大数据超时
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(m == 1 || n == 1)return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

//2013/7/4 14:44:21
//动态规划
//注意创建动态二维数组比较麻烦，所以使用一维数组模拟二维
class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int *data = new int[m * n]();

		for(int i = 0; i < m; ++i)
			data[i * n] = 1;
		for(int i = 0; i < n; ++i)
			data[i] = 1;

		for(int i = 1; i < m; ++i)
			for(int j = 1; j < n; ++j)
				data[i * n + j] = data[(i - 1) * n + j] + data[i * n + j - 1];

		int ret = data[(m - 1) * n + n - 1];
		delete[] data;
		return ret;
    }
};

//2013/7/4 14:58:12
//别人写的动态规划，空间复杂度为O(min(m, n))
public static int uniquePathsDP(int m, int n){
    int x = Math.min(m, n);
    int y = Math.max(m, n);
    int[] ret = new int[x];

    for(int i = 0; i < x; i++)
        ret[i] = 1;

    for(int i = 1; i < y; i++)
        for(int j = 1; j < x; j++)
        {
            ret[j] += ret[j - 1];
        }

    return ret[x - 1];
}

//2013/7/4 15:10:09
//最简单的方法是排列组合