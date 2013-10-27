/*

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

*/
//2013/7/21 19:27:24
//深度优先，做一些剪枝
//字符在ret中和自己相等的字符中的index应该等于在tp中和自己相等字符的index
//也可直接使用subsets I，只要在插入结果集之前判断有没有重复
class Solution {
public:
    void subsetDFS(std::vector<int> &tp, std::vector<std::vector<int> > &ret, std::vector<int> &S, int index, int cur_index, int tp_cur_index)
    {
      if(cur_index != tp_cur_index)return;

      ret.push_back(tp);
      if(index == S.size())
        return;

      int tpp;
      
      for(int i = index; i < S.size(); ++i)
      {
        // if((((!tp.empty()) && tp.back() != S[i]) || tp.empty()) && S[i] == S[i - 1])
        //   continue;
        if(tp.empty() || tp.back() != S[i])tpp = 1;
        else if(tp.back() == S[i])tpp = tp_cur_index + 1;
        
        tp.push_back(S[i]);

        if(i == 0 || S[i - 1] != S[i])subsetDFS(tp, ret, S, index + 1, 1, tpp);
        else subsetDFS(tp, ret, index + 1, cur_index + 1, tpp);
        
        tp.pop_back();
      }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<int> tp;
        std::vector<std::vector<int> > ret;

        sort(S.begin(), S.end());

        subsetDFS(tp, ret, S, 0, 1, 1);

        return ret;
    }
};





class Solution {
public:
    void dfs(vector<vector<int> > &ret, vector<int> &cur, vector<int> &S, int index)
    {
        ret.push_back(cur);
        
        for(int i = index; i < S.size(); ++i)
        {
            if(i == index || (i != index && S[i] != S[index]))
            {
                cur.push_back(S[i]);
                dfs(ret, cur, S, i + 1);
                cur.pop_back();
            }
            while(i + 1 < S.size() && S[i] == S[i + 1])++i;
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<int> > ret;
        vector<int> cur;
        int size = S.size();
        
        sort(S.begin(), S.end());
        dfs(ret, cur, S, 0);
        
        return ret;
    }
};
