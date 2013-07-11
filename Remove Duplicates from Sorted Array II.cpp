/*

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].

*/
//2013/7/11 14:06:23
//大水题
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(A == NULL || n == 0)return 0;

        int left = 0, right = 0;
        int cur_num = A[0];
        int cur = 0;
        while(right < n)
        {
        	if(A[right] == cur_num)
        	{
        		cur++;
        	}else{
        		cur_num = A[right];
        		cur = 1;       	
        	}

        	if(cur <= 2)
        	{
        		A[left] = A[right];
        		left++;
        	}
        	right++;
        }

        return left + 1;
    }
};