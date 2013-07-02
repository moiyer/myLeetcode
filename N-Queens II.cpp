/*

Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.

*/
//2013/7/2 9:23:02
//可以稍微改一下N-Queens解法来实现
//这里用了另外的解法，使用了位运算，高效巧妙
//基本思想是使用row，ld，rd来表示不能放的位置
//解析详见http://www.matrix67.com/blog/archives/266
class Solution {
public:
    int cnt,upper;
    int totalNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       cnt = 0;
       upper = (1<<n)-1 ;
       Queen(0,0,0);
       return cnt;

    }
    void Queen(int row,int ld,int rd)
    {
          int pos,p;
          if(row!=upper)
            {
                pos = upper & (~(row | ld |rd));
                while(pos!=0)
                {
                    p = pos & (-pos);
                    pos = pos - p;
                    Queen(row+p,(ld+p)<<1,(rd+p)>>1);
                }
            }
         else ++cnt;
    }
};