/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

//2013/6/14 14:09:48
//基本思路是从后往前扫描，找到非递减的一个
//这种循环的写法很好，设置多个变量控制出口，代码很简洁
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size  = num.size();
        if(size <= 1)return;

        int left = size - 2;
        int right = size - 1;
        int flag = size - 1;
        while(1)
        {
        	if(num[left] >= num[right])
        	{
        		--left;
        		--right;
        		if(left < 0)break;
        		continue;
        	}else{
        		if(num[flag] > num[left])
        		{
        			break;
        		}else
        		{
        			--flag;
        			continue;
        		}
        	}
        }

        if(right == 0)
        {
        	sort(num.begin(), num.end());
        	return;
        }
        swap(num[left], num[flag]);
        sort(num.begin() + left + 1, num.end());
        return;
    }
};