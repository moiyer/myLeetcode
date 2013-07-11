/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

*/
//2013/7/11 13:11:38
//深度优先
class Solution {
public:
	bool dfs(std::vector<std::vector<char> > &board, std::vector<std::vector<int> > &used, string &word, int index, int i, int j)
	{
		if(index == word.size())return true;
		if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || used[i][j] == 1)
			return false;

		bool ret = false;
		if(board[i][j] == word[index])
		{
			used[i][j] = 1;
			ret = dfs(board, used, word, index + 1, i - 1, j) || \
				dfs(board, used, word, index + 1, i , j - 1) || \
				dfs(board, used, word, index + 1, i + 1, j) || \
				dfs(board, used, word, index + 1, i , j + 1);

			if(!ret)used[i][j] = 0;
		}

		return ret;
	}

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int word_size = word.size();
        if(word_size == 0)return true;

        int m = board.size();
        int n = board[0].size();
        std::vector<std::vector<int> > used(m, std::vector<int>(n));
        for(int i = 0; i < m; ++i)
        	for(int j = 0; j < n; ++j)
        		used[i][j] = 0;

        for(int i = 0; i < m; ++i)
        	for(int j = 0; j < n; ++j)
        	{
        		if(board[i][j] == word[0])
        			if(dfs(board, used, word, 0, i, j))return true;
        	}

        return false;
    }
};