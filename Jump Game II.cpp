/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)


*/
//2013/6/28 16:53:23
//简单的dfs，注意数组中可能有0
//大数据超时
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       if(A == NULL || n <= 1)return 0;
       if(A[0] == 0)return INT_MIN;//这一行注意加上

       int step = INT_MAX;
       int cur = 0;
       if(n <= A[0])return 1;
       else
       {
       		for(int i = 1; i <= A[0]; ++i)
       		{
       			cur = jump(A + i, n - i);
       			if(cur >= 0 && cur < step)step = cur;//注意判断cur >= 0
       		}
       		++step;
       }

       return step;
    }
};

//2013/6/28 17:20:51
//动态规划。其实上面的方法重复计算了很多次，所以考虑使用一个数组记录步数
//还是大数据超时
class Solution {
public:
	int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int *minStep = new int[n]();

		int j = 0;
		int curMin = 0;
		for(int i = n - 2; i >= 0; --i)
		{
			if(A[i] == 0)minStep[i] = -1;
			curMin = INT_MAX;
			for(j = 1;  j <= A[i]; ++j)
			{
				if(i + j >= n)
				{
					curMin = 0;
					break;
				}
				if(minStep[i + j] >= 0 && curMin > minStep[i + j])
					curMin = minStep[i + j];
			}

			if(curMin == INT_MAX)minStep[i] = -1;
			else minStep[i] = curMin + 1;
		}

    int rt = minStep[0];
    delete[] minStep;

		return rt;
	}
};


//2013/6/28 17:19:26
//贪心法，别人写的。O(n)
//从左往右记录能到达的最远位置i + A[i]
class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 1) return 0;
        
        int pos = 0;
        int far = 0;
        
        for (int step = 1; pos <= far; step++) {
            for (int stop = far; pos <= stop; pos++) {
                far = max(far, pos + A[pos]);
                if (far >= n - 1) return step;
            }
        }
        
        return 0;
    }
};