/*

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/

//2013/6/9 22:18:08
//这也是一道经典递归题目，不过要记录现有'(',括号总数可用卡特兰数表示，1/n*C(2n,n)
class Solution {
public:

	void parenthesisIte(string& tmp, vector<string>& v, int pos, int size, int left, int left_total)
	{
		if(pos == size)
		{
			v.push_back(tmp);
			return;
		}

		if(left == 0)
		{
			tmp.push_back('(');
			parenthesisIte(tmp, v, pos + 1, size, left + 1, left_total + 1);
			tmp.pop_back();
		}else
		{
			if(left_total < size / 2)
			{
				tmp.push_back('(');
				parenthesisIte(tmp, v, pos + 1, size, left + 1, left_total + 1);
				tmp.pop_back();
			}

			tmp.push_back(')');
			parenthesisIte(tmp, v, pos + 1, size, left - 1, left_total);
			tmp.pop_back();
		}
	} 

    vector<string> generateParenthesis(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string tmp;
        std::vector<string> result;
        parenthesisIte(tmp, result, 0, n * 2, 0, 0);
        return result;
    }
};