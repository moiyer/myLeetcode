/*

Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

*/
//2013/7/16 15:39:41
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(n <= 0)return;
        if(m == 0)
        {
        	for(int i = 0; i < n; ++i)
        		A[i] = B[i];
        }

        int i = m - 1;
        int j = n - 1;
        while(i >= 0 && j >= 0)
        	{
        		if(A[i] > B[j])
        		{
        			A[i + j + 1] = A[i];
        			--i;
        		}else
        		{
        			A[i + j + 1] = A[j];
        			--j;
        		}
        	}

        while(j >= 0)
        	A[j--] = B[j--];

        return;
    }
};