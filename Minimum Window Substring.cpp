/*

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.

*/
//2013/7/10 11:06:35
//使用两个游标动态维护一个窗口,使用额外空间保存现在状态下已有的T中字符
//注意T中的字符可能重复
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        std::vector<std::vector<int> > v(256, std::vector<int> w(1, -1));

        int size_S = S.size();
        int size_T = T.size();

        for(int i = 0; i < size_T; ++i)
        {
        	++v[i][0];
        }

        for
    }
};


//别人写的，思路差不多，但是没有详细记录现在窗口的状态
class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int nT = T.size();
        int nS = S.size();
        
        int needToFind[256] = {0};
        for (int i = 0; i < nT; ++i)
            ++needToFind[T[i]];
        int hasFound[256] = {0};
        int minBegin;
        int minEnd;
        int minWindow = nS + 1;
        int count = 0;
        
        char ch;
        for (int begin = 0, end = 0; end < nS; ++end)
        {
            if (needToFind[S[end]] == 0)
                continue;
            ch = S[end];
            ++hasFound[ch];
            if (hasFound[ch] <= needToFind[ch])
                ++count;
                
            if (count == nT)
            {
                while (needToFind[S[begin]] == 0
                || hasFound[S[begin]] > needToFind[S[begin]])
                {
                    if (hasFound[S[begin]] > needToFind[S[begin]])
                        --hasFound[S[begin]];
                    ++begin;
                }
                
                int length = end - begin + 1;
                if (length < minWindow)  
                {
                    minBegin = begin;
                    minEnd = end;
                    minWindow = length;
                }
            }
        }
        
        return minWindow <= nS ? S.substr(minBegin, minEnd-minBegin+1) : "";
    }
};