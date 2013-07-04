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
//有点水
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

        char *result = new char[n + 1];   //这里用vector比用数组要好
        for(int i = 1; i <= n; ++i)
            result[i] = i + '0';

        int cur_index = 1;
        int cur_number = 0;
        while(cur_index < n && k >= 1)
        {
        	cur_number = (k - 1) / data[n - cur_index];
            sort(result + cur_index, result + n + 1);//这里别忘了
            swap(result[cur_index], result[cur_index + cur_number]);
        	k -= cur_number * data[n - cur_index];
        	cur_index++;
        }

        string ret(result + 1, n);
        delete[] data;
        delete[] result;

        return ret;
    }
};