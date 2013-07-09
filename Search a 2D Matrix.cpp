/*

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.

*/
//2013/7/9 21:47:52
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = matrix.size();
        int n = matrix[0].size();

        long l = 0, r = m * n - 1;
        long mid = 0;
        while(l <= r)
        {
        	mid = (l + r) >> 1;
        	if(target == matrix[mid / n][ mid % n])
        		break;
        	else if(target < matrix[mid / n][ mid % n])
        		r = mid - 1;
        	else l = mid + 1;
        }

        if(matrix[mid / n][mid % n] == target)
        	return true;
        else return false;
    }
};