/*

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

*/
//2013/7/16 14:54:47
//开始想错了，以为只要S1和S2的字符集相同就一定ok，其实不对，如"abcde"和"dbeac"
//三维动态规划，别人写的
//f(i, j, n) = || ((f(i, j, m) && f(i + m, j + m, n - m)) || f(i, j + n - m, m) && f(i + m, j, n - m)) for 1 < m < n 
//where f(i, j, n) is true iff substring starts at s1[i] and substring starts at s2[j] both with length n are scrambled
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (s2.size() != n) return false;

        bool f[n][n][n];

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                f[i][j][0] = s1[i] == s2[j];

        for (int l=1; l<n; l++) {
            for (int i=0; i+l<n; i++) {
                for (int j=0; j+l<n; j++) {
                    f[i][j][l] = false;
                    for (int k=0; k<l; k++) {
                        if (f[i][j][k] && f[i+k+1][j+k+1][l-1-k]
                            || f[i][j+l-k][k] && f[i+k+1][j][l-1-k]) {
                            f[i][j][l] = true;
                            break;
                        }
                    }
                }
            }
        }

        return f[0][0][n-1];
    }
};