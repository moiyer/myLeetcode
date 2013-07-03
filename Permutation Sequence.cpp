/*

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive

*/
//2013/7/3 20:18:29
class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *data = new int[n + 1]();
        data[0] = 1;
        for(int i = 1; i <= n; ++i)
        	data[i] = data[i - 1] * i;

        if(k > data[n] || k <= 0)return NULL;

        string ret;
        int cur_index = n;
        int cur_number = 0;
        while(cur_index >= 1)
        {
        	cur_number = k / data[cur_index - 1] + 1;
        	ret.push_back(cur_number + '0');
        	k %= data[cur_index - 1];
        	cur_index--;
        }
        
        return ret;
    }
};