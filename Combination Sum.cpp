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
//典型的回溯，递归实现，速度较慢，解法有问题,见注释
//其实回溯也是对树的一种遍历
class Solution {
public:
	void comIter(std::map<std::vector<int>, bool> &result, std::vector<int> &com, int num, std::vector<int>& candidates, int target)
	{
		if(target < 0)return;
		else if(0 == target)
		{
			if(0 == num)
			{
				sort(com.begin(), com.end());
				result[com] = true;
			}
			return;
		}
		if(0 == num)return;

		int cSize = candidates.size();
		for(int i = 0; i < cSize && candidates[i] <= target; ++i)
		{
			com.push_back(candidates[i]);
			comIter(result, com, num - 1, candidates, target - candidates[i]);
			com.pop_back();//不能这样，因为可能因为排序，com的序列已经改变，pop_back时不是pop掉43行插入的值

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

        for(auto& x: tmp)//C++11新特性，auto是由编译器自动确定类型
        	result.push_back(x.first);
        return result;
    }
};


//2013/6/23 10:13:28
//修改后的解法，在递归时不排序，而将排序放在最后结果统计时,这时可以不使用map，而是用set
//还是有问题
class Solution {
public:
    void comIter(std::vector<std::vector<int>> &result, std::vector<int> &com, int num, std::vector<int>& candidates, int target)
    {
        if(target < 0)return;
        else if(0 == target)
        {
            if(0 == num)
            {
                //sort(com.begin(), com.end());
                //result[com] = true;修改后不使用map，result参数是一个vector
                result.push_back(com);
            }
            return;
        }
        if(0 == num)return;

        int cSize = candidates.size();
        for(int i = 0; i < cSize && candidates[i] <= target; ++i)
        {
            com.push_back(candidates[i]);
            comIter(result, com, num - 1, candidates, target - candidates[i]);
            com.pop_back();//修改后可以直接pop_back

        }
        return;
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > result;
        set<std::vector<int> > tmp;
        std::vector<int> com;

        for(int i = 1; i <= target; ++i)
            comIter(result, com, i, candidates, target);

        for(auto& x: result)//C++11新特性，auto是由编译器自动确定类型
            {
                sort(x.begin(), x.end());
                tmp.insert(x);
            }

        result.clear();
        for(auto& it : tmp)
            result.push_back(it);
        return result;
    }
};

//2013/6/25 19:19:48
/** 整理的提交代码
 * 处理复杂度为
 * 主要思路：回溯法
 */
class Solution {
private:
    const int index_count;
    vector<vector<int> > results;
public:
    Solution() : index_count(10000) {};
    // index记录当前找到的候选数字，n表示当前正在找第几个，n是index的下标不是candidates的下标
    void backtrace(int target, int sum, vector<int> &candidates, int index[], int n)
    {
        if (sum > target)
        {
            return; // 回溯
        }
        if (sum == target)
        {
            vector<int> result;
            for (int i = 1; i <= n; ++i)
            {
                result.push_back(candidates[index[i]]); 
            }
            results.push_back(result);
            return; // 此处可以不加，如果不加return由于都是正整数，到下面的计算时会多进行一次无用的递归。
        }

        // 深度搜索，为了避免重复，每次从当前候选项索引到结尾，上面的i=index[n]可以看出
        for (int i = index[n]; i < candidates.size(); ++i)
        {
            index[n+1] = i; // 记录当前考察的候选项索引
            backtrace(target, sum+candidates[i], candidates, index, n+1);
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());

        int *index = new int[index_count];
        memset(index, 0, sizeof(int)*index_count);
        
        results.clear();    // 提交到leetcode的测试系统上必须添加，它应该是使用一个对象测试所有测试用例。
        backtrace(target, 0, candidates, index, 0);

        delete[] index;

        return results;
    }
};


//2013/6/22 22:42:00
//这个其实是一棵树的遍历，别人的DFS实现的，之前就考虑好了去重，速度快
class Solution {
     void find_subset(vector<int>::iterator first,vector<int>::iterator last, 
                      vector<int> &comb, int target, vector<vector<int>> &ret){
         if(target == 0)
             ret.push_back(comb);
         if(target < 0)
             return;
         vector<int>::iterator it;
         for(it = first; it != last && *it <= target; it++){
             comb.push_back(*it);
             find_subset(it, last, comb, target - *it, ret);
             comb.pop_back();
         }
         
     }
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> ret;
        unique(candidates.begin(), candidates.end());
        sort(candidates.begin(), candidates.end());
        vector<int> a;
        
        find_subset(candidates.begin(), candidates.end(), a, target, ret);
        return ret;
    }
};