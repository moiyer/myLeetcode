/*

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.

*/

//2013/6/17 17:13:46
//深度优先的解法，代码逻辑清晰
class Solution {
public:
    vector<vector<bool> > rows;
    vector<vector<bool> > cols;
    vector<vector<bool> > blocks;

    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        rows.clear();
        cols.clear();
        blocks.clear();
        rows.resize(9, vector<bool>(9, false));
        cols.resize(9, vector<bool>(9, false));
        blocks.resize(9, vector<bool>(9, false));

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    rows[i][c - '1'] = cols[j][c - '1'] = blocks[(i / 3) * 3 + j / 3][c - '1'] = true;
                }
            }
        }

        sub(board, 0);
    }

    bool sub(vector<vector<char> > &board, int index) {

        while (index < 81 && board[index / 9][index % 9] != '.')
            index++;

        if (index == 81) return true;

        int row = index / 9, col = index % 9;
        for (int i = 0; i < 9; ++i) {
            if (rows[row][i] || cols[col][i] || blocks[(row / 3) * 3 + col / 3][i]) continue;
            rows[row][i] = cols[col][i] = blocks[(row / 3) * 3 + col / 3][i] = true;
            board[row][col] = '1' + i;
            if (sub(board, index + 1))
                return true;
            board[row][col] = '.';
            rows[row][i] = cols[col][i] = blocks[(row / 3) * 3 + col / 3][i] = false;
        }

        return false;
    }
};