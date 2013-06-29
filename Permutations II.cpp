/*

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

*/

//2013/6/29 21:02:12
//只是稍微改了一下Permutations,将num排序，然后跳过重复的选择
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
		int last = num[0];
		for(int i = 0; i < num.size(); ++i)
		{
			tp = num[i];
			if(i != 0 && last == tp)continue;
			cur.push_back(num[i]);
			num.erase(num.begin() + i);
			back_trace(cur, ret, num);
			num.insert(num.begin() + i, tp);
			cur.pop_back();
			last = tp;
		}
	}

    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
    	std::vector<int> cur;
    	std::vector<std::vector<int> > ret;

    	sort(num.begin(), num.end());
    	back_trace(cur, ret, num);

    	return ret;    
    }
};