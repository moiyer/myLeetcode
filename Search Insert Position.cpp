/*

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0

*/

//2013/6/15 22:51:52
//简单的二分搜索，循环实现
class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n - 1;
        int middle;

        if(A == NULL || n <= 0)return -1;

        while(l <= r)
        {
        	middle = (l + r) >> 1;
        	if(A[middle] < target)
        	{
        		l = middle + 1;
        		continue;
        	}else if(A[middle] > target)
        	{
        		r = middle - 1;
        		continue;
        	}else{
        		return middle;
        	}
        }

        return l;
    }
};