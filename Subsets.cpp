/*

Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/
//2013/7/10 16:58:08
//深度优先
class Solution {
public:
    void dfs(std::vector<std::vector<int> > &ret, std::vector<int> &tmp, std::vector<int> &data, int start)
    {
      
      ret.push_back(tmp);
      if(start == data.size())
        return;

      for(int i = start; i < data.size(); ++i)
      {
        tmp.push_back(data[i]);
        dfs(ret, tmp, data, i + 1);
        tmp.pop_back();
      }
    }

    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > ret;
        std::vector<int> tmp;

        sort(S.begin(), S.end());

        dfs(ret, tmp, S, 0);
        return ret;
    }
};