//2013/6/19 15:01:22
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