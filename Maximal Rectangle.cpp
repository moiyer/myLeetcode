/*

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

*/
//2013/7/16 9:39:31
//DP。用f[i][j]来记录i行以j列为结尾，往前连续的1的个数。然后再一个O(n^3)的循环来找以(i, j)为右下角的矩形最大的1的面积。
//不是自己写的，O(n^3)
class Solution {
 private:
     int f[1000][1000];
 public:
     int maximalRectangle(vector<vector<char> > &matrix) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         for(int i = 0; i < matrix.size(); i++)
             f[i][0] = matrix[i][0] == '1' ? 1 : 0;
             
         for(int i = 0; i < matrix.size(); i++)
             for(int j = 1; j < matrix[i].size(); j++)
                 f[i][j] = matrix[i][j] == '1' ? f[i][j-1] + 1 : 0;
                 
         int ret = 0;
         
         for(int i = 0; i < matrix.size(); i++)
             for(int j = 0; j < matrix[i].size(); j++)
             {
                 int k = i;
                 int width = INT_MAX;
                 
                 while(k >= 0)
                 {
                     if (f[k][j] == 0)
                         break;
                     
                     width = min(width, f[k][j]);
                 
                     ret = max(ret, width * (i - k + 1));   
                     
                     k--;                   
                 }
             }
             
         return ret;
     }
 };

//2013/7/16 13:57:17
//利用Largest Rectangle in Histogram的方法进行优化，求第i行为最底边的长方形时求最直方图最大矩形
 //别人写的，O(n^2)
 int maximalRectangle(vector<vector<char> >& mat)
	{
		if (mat.empty()) return 0;
		int m=mat.size();
		int n=mat[0].size();
		vector<vector<int> > grid(m,vector<int>(n,0));

		int i,j;
		for(i=0;i<n;i++)
			grid[0][i]=mat[0][i]-'0';
		for(i=1;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				if (mat[i][j]=='0')
					grid[i][j]=0;
				else
				{
					grid[i][j]=grid[i-1][j]+mat[i][j]-'0';
				}	
			}
		}

		int ans=0;
		for(i=0;i<m;i++)
		{
			int curMax=largestRectangleArea(grid[i]);
			ans=max(ans,curMax);
		}
		return ans;
	}