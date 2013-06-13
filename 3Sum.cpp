/*

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

*/

//2013/6/8 14:50:57
//较简单
//设置3个游标left,middle和right，固定left，然后middle和right向中间逼近，注意去重
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //if(num.size() < 3)return NULL;

        int nSize = num.size();
        int left = 0;
        int middle, right, sum, last;

        std::vector<std::vector<int>> result;

        sort(num.begin(), num.end());
        while(left <= nSize - 3)
        {
        	middle = left + 1;
        	right = nSize - 1;
        	while(middle < right)
        	{
        		sum = num[left] + num[middle] + num[right];
        		if(sum == 0)
        		{
        			std::vector<int> v;
        			v.push_back(num[left]);
        			v.push_back(num[middle]);
        			v.push_back(num[right]);
        			result.push_back(v);
        			last = num[middle++];
        			while(middle < right && num[middle] == last)middle++;
        		}else if(sum < 0)
        		{
        			last = num[middle++];
        			while(middle < right && num[middle] == last)middle++;
        		}else
        		{
        			last = num[right--];
        			while(right > middle && num[right] == last)right--;
        		}
        	}

        	last = num[left++];
        	while(left <= nSize - 3 && num[left] == last)left++;
        }

        return result;
    }


};