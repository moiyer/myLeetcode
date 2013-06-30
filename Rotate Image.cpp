/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

*/

//2013/6/29 21:26:26
//水题
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int mSize = matrix.size();

        int tp = 0;
        for(int i = 0; i < mSize >> 1; ++i)
        {
        	for(int j = i; j < mSize - i - 1; ++j)
        	{
        		tp = matrix[i][j];
        		matrix[i][j] = matrix[mSize - 1 - j][i];
        		matrix[mSize - 1 -j][i] = matrix[mSize - i - 1][mSize - j - 1];
                matrix[mSize - i - 1][mSize - 1 - j] = matrix[j][mSize - i - 1];
                matrix[j][mSize - i - 1] = tp;
        	}
        }
    }
};