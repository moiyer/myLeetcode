/*

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

//2013/6/27 16:49:30
//题目的最后一行，要求O(n)实际上暗示了用hash，但是又说要contant space，就没法再开新空间来建hash。
//正好这个题目中处理的是1到n的数据，提供了一个将输入的数组同时用作hash表的可能性。
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cur, next_num;
        for(int i = 0; i < n; ++i)
        {
        	cur = A[i];
        	while(cur > 0 && cur <= n && cur != A[cur - 1])
        	{
        		next_num = A[cur - 1];
        		A[cur - 1] = cur;
        		cur = next_num;
        	}
        }

        for(int i = 0; i < n; ++i)
        	if(A[i] != i + 1)return i + 1;

        return n + 1;
    }
};