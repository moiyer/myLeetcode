/*

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

*/
//2013/7/10 15:35:19
//典型回溯
class Solution {
public:
    void backtrace(std::vector<std::vector<int> > &ret, std::vector<int> &tmp, int nstart, int n, int index, int k)
    {
    	if(index == k && nstart <= n + 1)
    	{
    		ret.push_back(tmp);
    		return;
    	}

    	for(int i = nstart; i <= n; ++i)
    	{
    		tmp.push_back(i);
    		backtrace(ret, tmp, i + 1, n, index + 1, k);
    		tmp.pop_back();
    	}
    }

    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > ret;
        std::vector<int> tmp;

        backtrace(ret, tmp, 1, n, 0, k);
        return ret;
    }
};