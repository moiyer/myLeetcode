/*

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

*/
//2013/6/11 20:08:06
//这是一道很水的题
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int last, i;
        int result = 0;
        int tail = 0;

        if(A == NULL || n <= 0)return 0;
        
        last = A[0];
        result = 1;
        tail = 0;
        for(i = 1; i < n; ++i)
        {
        	if(last == A[i])continue;
        	else 
        	{
        		last = A[i];
        		tail++;
        		A[tail] = A[i];
        		result++;
        	}
        }

        return result;
    }
};