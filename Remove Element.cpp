/*

Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

*/

//2013/6/11 20:14:33
//这是一道水题
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A == NULL || n <= 0)return 0;

        int i, tail;

        tail = 0;
        for(i = 0; i < n; ++i)
        {
        	if(A[i] == elem)continue;
        	else
        	{
        		A[tail++] = A[i];
        	}
        }

        return tail;
    }
};