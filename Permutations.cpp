/*

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

*/

//2013/6/29 20:38:14
//经典的回溯，没有使用swap的方法
class Solution {
public:
	void back_trace(std::vector<int> &cur, std::vector<std::vector<int> > &ret, std::vector<int> &num)
	{
		if(num.size() == 0)
		{
			ret.push_back(cur);
			return;
		}

		int tp = 0;
		for(int i = 0; i < num.size(); ++i)
		{
			tp = num[i];
			cur.push_back(num[i]);
			num.erase(num.begin() + i);
			back_trace(cur, ret, num);
			num.insert(num.begin() + i, tp);
			cur.pop_back();
		}
	}

    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	std::vector<int> cur;
    	std::vector<std::vector<int> > ret;

    	int nSize = num.size();
    	back_trace(cur, ret, num);

    	return ret;    
    }
};