/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*/
//2013/7/2 18:31:25
//动态规划，使用了一个外部数组，其实也可以不使用，直接记录data[]中的最大值即可
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *data = new int[n]();

        int sum = 0;
        int max_sum = 0;
        int max_data = INT_MIN;
        for(int i = 0; i < n; ++i)
        {
        	sum += A[i];
        	if(sum < 0)sum = 0;
        	data[i] = sum;
        	if(max_data < A[i])max_data = A[i];
        }

        for(int i = 0; i < n; ++i)
        	if(data[i] > max_sum)max_sum = data[i];

        if(max_sum == 0)max_sum = max_data;
        return max_sum;
    }
};

//2013/7/2 18:57:35
//分治法实现
class Solution {
public:
	int divide(int A[], int l, int r)
	{
		if(l == r)return A[l];

		int m = (l + r) >> 1;
		int left_sum = divide(A, l, m);
		int right_sum = divide(A, m + 1, r);

		int l_sum = 0;
		int l_m = INT_MIN;
		for(int i = m; i >= l; --i)
		{
			l_sum += A[i];
			if(l_sum > l_m)l_m = l_sum;
		}

		int r_sum = 0;
		int r_m = INT_MIN;
		for(int i = m + 1; i <= r; ++i)
		{
			r_sum += A[i];
			if(r_sum > r_m)r_m = r_sum;
		}

		int tp = max(left_sum, right_sum);
		return max(tp, l_m + r_m);
	}

    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return divide(A, 0, n - 1);
    }
};

//2013/7/2 19:13:59
//不使用外部数组
class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = A[0], sum = 0;
        for (int i = 0; i < n; ++i) {
            sum = max(sum + A[i], A[i]);
            ret = max(ret, sum);
        }
        return ret;
    }
};