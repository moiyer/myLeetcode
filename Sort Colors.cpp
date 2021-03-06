/*

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

*/
//2013/7/10 10:38:38
//设置游标，比较简单
class Solution {
public:
    void sortColors(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l, m, r;

        int next0 = 0;
        int next1 = 0;
        for(int i = 0; i < n; ++i)
        {
        	if(A[i] == 0)
        	{
        		//if(next0 < 0)
        		swap(A[i], A[next1]);
        		swap(A[next0], A[next1]);
        		++next0;
        		++next1;
        	}else if(A[i] == 1)
        	{
        		swap(A[i], A[next1]);
        		++next1;
        	}else{
        		;
        	}
        }
    }
};