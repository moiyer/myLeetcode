/*

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/
//与3Sum思路相同，设置3个游标，固定左边的，后面的两个向中间逼近
//2013/6/8 15:39:02

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {

        long long result = INT_MIN;//不能用声明为int，不然35和40行可能会溢出
        int nSize = num.size();
        int left, right, middle, sum;

        left = 0;
        sort(num.begin(), num.end());
        while(left < nSize - 2)
        {
        	middle = left + 1;
        	right = nSize - 1;

        	while(middle < right)
        	{
        		sum = num[left] +num[middle] + num[right];
        		if(sum == target)return target;
        		else if(sum < target)
        		{
        			if(abs(result - target) > abs(sum - target))
        				result = sum;
        			middle++;        			
        		}else
        		{
        			if(abs(result - target) > abs(sum - target))
        				result = sum;
        			right--;
        		}
        	}
        	left++;
        }

        return result;
    }
};