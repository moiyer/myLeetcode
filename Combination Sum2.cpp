//2013/6/19 15:01:22
/*

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

*/
//和Combination Sum差不多，回溯、dfs，注意去重
//注意重复的排重，如[1, 1],target=1时只应该输出[1]而不是[[1],[1]]
//如[2, 2, 2],target=4时应该输出[2, 2]而不是[[2, 2], [2, 2]]
//即相等的数在candidates中相等数的位置要和在com中相等数的位置相同
//参数candidates_num表示当前数在candidates的和自己相等的数的小数组中位置
//参数com_num表示当前数在com的和自己相等的数的小数组中位置
//只有candidates_num == com_num时才可以插入到com中
class Solution {
public:
	void dfs(std::vector<int> &candidates, std::vector<std::vector<int> > &rt, std::vector<int> &com, int left, int index, int candidates_num, int com_num)
	{
		if(left < 0)return;
		else if(left == 0)
		{
			rt.push_back(com);
			return;
		}

		int cSize = candidates.size();
		if(index == cSize)return;


		int tp;
		for(int i = index; i < cSize; ++i)
		{
			//去除重复
			if(i == 0 )candidates_num = 0;
			else if(candidates[i] == candidates[i - 1])candidates_num++;
			else candidates_num = 0;

			if(com.empty())com_num = 0;
			else if(com.back() == candidates[i])com_num++;
			else com_num = 0;

			if(candidates_num != com_num)continue;
			//end 去除重复
			com.push_back(candidates[i]);
			dfs(candidates, rt, com, left - candidates[i], i + 1, candidates_num, com_num);
			com.pop_back();

			if(com.back() == candidates[i])com_num--;//别忘了这一句
		}

		return;
	}

	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		std::vector<std::vector<int> > result;
		std::vector<int> com;

		sort(candidates.begin(), candidates.end());
		dfs(candidates, result, com, target, 0, 0, 0);
		return result;
	}
};