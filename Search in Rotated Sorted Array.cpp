/*

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/

//2013/6/15 20:40:49
//二分查找，复杂度O(lg n)
class Solution {
public:
	int findPivot(int A[], int left, int right)
	{
		if(left == right || A[left] < A[right])return left;

		int middle = (left + right) >> 1;
		if(middle == left)return right;

		if(A[middle] < A[left])
			return findPivot(A, left, middle);//注意不能用middle - 1，因为可能是middle
		else return findPivot(A, middle, right);
	}

	int bSearch(int A[], int left, int right, int target)
	{
		if(left > right)return -1;

		int middle = (left + right) >> 1;

		if(A[middle] == target)return middle;
		else if(A[middle] < target)return bSearch(A, middle + 1, right, target);
		else return bSearch(A, left, middle - 1, target);
	}

    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pivot = findPivot(A, 0, n - 1);
        if(pivot == 0)return bSearch(A, 0, n - 1, target);

        int l = bSearch(A, 0, pivot - 1, target);
        if( l == -1)
        	return bSearch(A, pivot, n - 1, target);
        else return l;
    }
};