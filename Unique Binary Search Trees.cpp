/*

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/
//2013/8/15 20:38:05
//f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-1)*f(0)
class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *data = new int[n + 1]();
        int ret = 0;

        data[0] = 1;
        data[1] = 1;
        data[2] = 2;
        int i = 3;
        int k = 0;
        for(; i <= n; ++i)
        {
        	k = 0;
        	while(k < i)
        	{
        		data[i] += data[k] * data[i - k - 1];
        		++k;
        	}
        }

        ret = data[n];
        delete [] data;
        return ret;
    }
};