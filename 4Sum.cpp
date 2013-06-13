/*

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ? b ? c ? d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)

*/

//2013/6/9 15:07:09
//O(n^3)，和3Sum相同的方法,只是设置4个游标
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int left, mLeft, mRight, right;
        int sum, last;
        int nSize = num.size();

        vector<vector<int> > result;

        if(nSize < 4)return result;

        sort(num.begin(), num.end());
        left = 0;
        while(left <= nSize - 4)
        {
        	mLeft = left + 1;
        	while(mLeft <= nSize - 3)
        	{
        		mRight = mLeft + 1;
        		right = nSize - 1;
        		while(mRight < right){
        			sum = num[left] + num[mLeft] + num[mRight] + num[right];

        			if(sum == target)
        			{
        				std::vector<int> v;
        				v.push_back(num[left]);
        				v.push_back(num[mLeft]);
        				v.push_back(num[mRight]);
        				v.push_back(num[right]);
        				result.push_back(v);
        				last = num[mRight];
        				++mRight;
        				while(mRight < right && num[mRight] == last)++mRight;
        			}else if(sum < target)
        			{
        				last = num[mRight];
        				++mRight;
        				while(mRight < right && num[mRight] == last)++mRight;
        			}else
        			{
        				last = num[right];
        				--right;
        				while(mRight < right && num[right] == last)--right;
        			}
        		}
        		last = num[mLeft];
        		++mLeft;
        		while(mLeft <= nSize - 3 && num[mLeft] == last)++mLeft;
        	}
        	last = num[left];
        	++left;
        	while(left <= nSize - 4 && num[left] == last)++left;
        }

        return result;
    }
};