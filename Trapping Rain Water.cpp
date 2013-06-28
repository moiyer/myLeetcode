/*

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

//2013/6/27 17:26:44
//没什么算法，要想到一种策略,O(n^2)
//for each bar, find the max height bar on the left and right. then for this bar it can hold min(max_left, max_right) - height
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lMax, rMax, curMax;
        int left, right;
        int sum = 0;

        if(A == NULL || n < 3)return 0;

        for(int i = 0; i < n; ++i)
        {
        	lMax = rMax = A[i];
        	for(left = i; left >= 0; --left)
        	{
        		if(A[left] > lMax)lMax = A[left];
        	}
        	for(right = i; right < n; ++right)
        	{
        		if(A[right] > rMax)rMax = A[right];
        	}
        	curMax = min(lMax, rMax);
        	sum += (curMax - A[i]);
        }

        return sum;
    }
};


//2013/6/28 13:25:19
//别人的写法，主要思想一样，但是效率高多了,O(n)
class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!A || !n) return 0;

        int mid = 0, water = 0, h = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] > A[mid])
                mid = i;
        }

        for (int i = 0; i < mid; ++i) {
            if (h > A[i])
                water += h - A[i];
            else
                h = A[i];
        }

        h = 0;
        for (int i = n - 1; i > mid; --i) {
            if (h > A[i])
                water += h - A[i];
            else
                h = A[i];
        }
        return water;
    }
};