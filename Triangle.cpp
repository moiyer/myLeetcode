/*

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.

*/
//2013/8/27 20:30:52
//简单动态规划
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size = triangle.size();
        int *data = new int[size]();

        data[0] = triangle[0][0];
        for(int i = 1; i < size; ++i)
        {
        	data[i] = data[i - 1] + triangle[i][i];
        	for(int j = i - 1; j >= 1; --j)
        		data[j] = (data[j - 1] < data[j] ? data[j - 1] : data[j]) + triangle[i][j];
        	data[0] += triangle[i][0];
        }

        int min = data[0];
        for(int i = 0; i < size; ++i)
        	if(min > data[i])min = data[i];

        delete [] data;
        return min;
    }
};