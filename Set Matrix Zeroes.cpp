/*

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

*/
//2013/7/9 14:25:33
//以第一行和第一列作为存储临时信息的地方,思路很好
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool row = false;
        bool column = false;

        int m = matrix.size();
        int n = matrix[0].size();

        for(int i = 0; i < m; ++i)
        {
        	if(matrix[i][0] == 0)
        	{
        		column = true;
        		break;
        	}
        }

        for(int j = 0; j < n; ++j)
        {
        	if(matrix[0][j] == 0)
        	{
        		row = true;
        		break;
        	}
        }

        for(int i = 1; i < m; ++i)
        	for(int j = 1; j < n; ++j)
        		if(matrix[i][j] == 0)
        		{
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}

        for(int i = 1; i < m; ++i)
        	if(matrix[i][0] == 0)
        		for(int j = 0; j < n; ++j)
        			matrix[i][j] = 0;

        for(int j = 1; j < n; ++j)
        	if(matrix[0][j] == 0)
        		for(int i = 0; i < m; ++i)
        			matrix[i][j] = 0;

        if(row)
        	for(int j = 0; j < n; ++j)
        		matrix[0][j] = 0;
        if(column)
        	for(int i = 0; i < m; ++i)
        		matrix[i][0] = 0;
    }
};