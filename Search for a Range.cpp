/*

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

//2013/6/15 22:15:40
//比较简单的二分查找，下次用循环实现
class Solution {
public:
	int findTarget(int A[], int size, int left, int right, int target, bool orient)
	{
		if(left > right)return -1;

		int middle = (left + right) >> 1;

		if(A[middle] < target)return findTarget(A, size, middle + 1, right, target, orient);
		else if(A[middle] > target)return findTarget(A, size, left, middle - 1, target, orient);
		else{
			if(orient)
				if(middle == 0 || A[middle - 1] < target)
					return middle;
				else return findTarget(A, size, left, middle - 1, target, orient);
			else 
				if(middle == size - 1 || A[middle + 1] > target)
					return middle;
				else return findTarget(A, size, middle + 1, right, target, orient);
		}
	}

    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> d(2, -1);
        int l = findTarget(A, n, 0, n - 1, target, true);
        if(l == -1)return d;
        int r = findTarget(A, n, 0, n - 1, target, false);
        std::vector<int> v;
        v.push_back(l);
        v.push_back(r);
        return v;
    }
};