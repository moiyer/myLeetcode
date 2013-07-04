/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

*/
//2013/7/4 19:52:03
//动态规划
class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        int n = grid[0].size();

        for(int i = n - 2; i >= 0; --i)
        	grid[m - 1][i] += grid[m - 1][i + 1];
        for(int i = m - 2; i >= 0; --i)
        	grid[i][n - 1] += grid[i + 1][n - 1];

        for(int i = m - 2; i >= 0; --i)
        	for(int j = n - 2; j >= 0; --j)
        	{
        		grid[i][j] += min(grid[i + 1][j], grid[i][j + 1]);
        	}

        return grid[0][0];
    }
};