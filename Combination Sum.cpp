/*

Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, � , ak) must be in non-descending order. 
(ie, a1 ? a2 ? � ? ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

*/

//2013/6/18 14:30:22
//典型的递归
class Solution {
public:
	void comIter(std::map<std::vector<int>, bool> &result, std::vector<int> &com, int num, std::vector<int> candidates, int target)
	{
		if(target < 0)return;
		if(0 == num)
		{
			if(0 == target)
			{
				sort(com.begin(), com.end());
				result[com] = true;
			}
			return;
		}

		int cSize = candidates.size();
		for(int i = 0; i < cSize; ++i)
		{
			com.push_back(candidates[i]);
			comIter(result, com, num - 1, candidates, target - candidates[i]);
			com.pop_back();
		}
		return;
	}

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > result;
        map<std::vector<int> , bool> tmp;
        std::vector<int> com;

        for(int i = 1; i <= target; ++i)
        	comIter(tmp, com, i, candidates, target);

        int mSize = tmp.size();
        for(int i = 0; i < mSize; ++i)
        	result.push_back(tmp[i]->first);
        return result;
    }
};