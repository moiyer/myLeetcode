/*

The n-queens puzzle is the problem of placing n queens on an n�n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

*/

//2013/6/30 19:40:19
//经典回溯
class Solution {
public:
	bool check(int *cur, int index, int size)
	{
		for(int i = index - 1; i >= 0; --i)
		{
			if(abs(cur[index] - cur[i]) == abs(index - i))
				return false;
		}
		return true;
	}

	void getNQueens(std::vector<std::vector<string> > &ret, int *cur, int index, int size)
	{
		if (index == size)
		{
			std::vector<string> v;
			for(int i = 0; i < size; ++i)
				{
					string s(size, '.');
					s[cur[i]] = 'Q';
					v.push_back(s);
				}
			ret.push_back(v);
		}

		for(int i = index; i < size; ++i)
		{
			swap(cur[index], cur[i]);
			if(check(cur, index, size))
				getNQueens(ret, cur, index + 1, size);
			swap(cur[index], cur[i]);
		}
	}

    vector<vector<string> > solveNQueens(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int *data = new int[n];
        for(int i = 0; i < n; ++i)
        	data[i] = i;

        std::vector<std::vector<string> > ret;
        getNQueens(ret, data, 0, n);

        return ret;
    }
};