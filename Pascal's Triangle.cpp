/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/
//2013/8/27 19:49:14
//水题
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > ret;
        std::vector<int> cur;

        if(numRows < 1)return ret;
        if(numRows >= 1)
        {
            cur.push_back(1);
            ret.push_back(cur);
        }

        for(int i = 1; i < numRows; ++i)
        {
            cur.clear();
            cur.push_back(1);
            for(int j = 1; j < i; ++j)
        		cur.push_back(ret.back()[j] + ret.back()[j - 1]);
        	cur.push_back(1);
        	ret.push_back(cur);
        }

        return ret;
    }
};