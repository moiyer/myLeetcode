/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

*/
//2013/7/2 19:31:06
//dfs算法
//大数据超时
class Solution {
public:
	bool dfs(int A[], int cur, int n)
	{
		if(cur == n - 1)return true;
		if(A[cur] == 0)return false;

		for(int i = 1; i <= A[cur]; ++i)
		{
			if(dfs(A, cur + i, n))return true;
		}
	}

    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dfs(A, 0, n);
    }
};

//2013/7/2 19:52:20
//贪心
class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int reach = 1;
        for (int i = 0; i < reach && reach < n; ++i)
            reach = max(reach, A[i] + i + 1);
        return reach >= n;
    }
};