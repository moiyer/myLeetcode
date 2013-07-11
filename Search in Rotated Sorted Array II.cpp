/*

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

*/
//2013/7/11 15:40:53
//二分查找,有问题
class Solution {
public:
	int findPivot(int A[], int left, int right)
	{
		if(left >= right)return (left + right) >> 1;

		int mid = (left + right) >> 1;

		if(A[mid] > A[left])
			return findPivot(A, mid + 1, right);
		if(A[mid] < A[right])
			return findPivot(A, left, mid);
		return findPivot(A, left + 1, right);
	}

	bool bSearch(int A[], int left, int right, int target)
	{
		if(left < 0 || right < 0)return false;
		if(left > right)return false;

		int mid = (left + right) >> 1;
		if(A[mid] == target)return true;
		if(A[mid] < target)return bSearch(A, mid + 1, right, target);
		if(A[mid] > target)return bSearch(A, left, mid - 1, target);
	}

    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int pivot = findPivot(A, 0, n - 1);

        return bSearch(A, 0, pivot - 1, target) || bSearch(A, pivot, n - 1, target);
    }
};

//2013/7/11 17:22:34
//别人写的，直接二分查找
bool search(int A[], int n, int key) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = l + (r - l)/2;
        if (A[m] == key) return true; //return m in Search in Rotated Array I
        if (A[l] < A[m]) { //left half is sorted
            if (A[l] <= key && key < A[m])
                r = m - 1;
            else
                l = m + 1;
        } else if (A[l] > A[m]) { //right half is sorted
            if (A[m] < key && key <= A[r])
                l = m + 1;
            else
                r = m - 1;
        } else l++;
    }
    return false;
}