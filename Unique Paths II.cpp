/*

Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

*/
//2013/7/4 15:57:23
//稍微改一下Unique Paths
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

  		if(m == 0 || n == 0)return 0;

        int *data = new int[m * n]();

        bool can_reach = true;
		for(int i = 0; i < m; ++i)
			if(!can_reach)data[i * n] = 0;
			else if(obstacleGrid[i][0] == 1)data[i * n] = 0, can_reach = false;
				else data[i * n] = 1;

		can_reach = true;
		for(int i = 0; i < n; ++i)
			if(!can_reach)data[i] = 0;
			else if(obstacleGrid[0][i] == 1)data[i] = 0, can_reach = false;
			else data[i] = 1;

		for(int i = 1; i < m; ++i)
			for(int j = 1; j < n; ++j)
				if(obstacleGrid[i][j] != 1)
					data[i * n + j] = data[(i - 1) * n + j] + data[i * n + j - 1];
				else data[i * n + j] = 0;

		int ret = data[(m - 1) * n + n - 1];
		delete[] data;
		return ret;
    }
};